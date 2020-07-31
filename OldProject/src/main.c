/**
 * Questo è lo starting point del programma.
 */

#include "utils.h"
#include "grocerystore.h"
#include "config.h"
#include "threadpool.h"
#include "signal_handler.h"
#include "client.h"
#include "cashier.h"
#include "logger.h"
#include "manager.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

#define DEFAULT_CONFIG_FILE "./config.txt"
#define ARG_CONFIG_FILE "-c"
#define ERROR_READ_CONFIG_FILE "Unable to read config file"
#define MESSAGE_CONFIG_FILE_NOT_VALID "Il file di configurazione presenta valori non corretti o mancanti\n"
#define MESSAGE_STORE_IS_OPEN "Supermercato aperto!\n"
#define MESSAGE_STORE_IS_CLOSING "\rChiusura del supermercato...\n"

char *parseArgs(int argc, char **args);
thread_pool_t *cashiers_create(cashier_t **cashiers_args, grocerystore_t *gs, int size);
thread_pool_t *clients_create(grocerystore_t *gs, int size, int t, int p, cashier_t **cashiers_args, size_t no_of_cashiers);

//grocerystore -c pathtoconfigfile
int main(int argc, char** args) {
    int err, i;
    grocerystore_t *gs;
    gs_state closing_state;         //Stato di chiusura del supermercato
    pthread_t handler_thread, manager_thread;       //Thread che gestisce i segnali e thread che riceve ad intervalli regolari le informazioni dalle casse
    thread_pool_t *clients, *cashiers;
    cashier_t **cashiers_args;      //Array contenente l'argomento passato per ogni cassiere
    manager_args *manager;
    manager_queue *mqueue;
    client_thread_stats **clients_stats;    //Array con le statistiche di tutti i clienti
    cashier_thread_stats **cashiers_stats;  //Array con le statistiche di tutti i cassieri
    FILE *logfile;

    //Eseguo il parsing del nome del file di configurazione
    char *configFilePath = parseArgs(argc, args);
    //Leggo il file di configurazione
    Config *config = loadConfig(configFilePath);
    EQNULL(config, perror(ERROR_READ_CONFIG_FILE); exit(EXIT_FAILURE))

    //Controllo se il file di configurazione è valido, altrimenti termino ed informo
    if (isValidConfig(config)) {
        printConfig(config);
    } else {
        printf(MESSAGE_CONFIG_FILE_NOT_VALID);
        printConfig(config);
        free_config(config);
        exit(EXIT_FAILURE);
    }

    //Creo lo store
    gs = grocerystore_create(config->c);
    EQNULL(gs, perror("grocerystore_create"); exit(EXIT_FAILURE))

    mqueue = alloc_manager_queue();
    EQNULL(mqueue, perror("alloc manager queue"); exit(EXIT_FAILURE))

    //Inizializzo tutti i cassieri senza farli partire
    cashiers_args = (cashier_t**) malloc(sizeof(cashier_t*)*config->k);
    EQNULL(cashiers_args, perror("cashiers_args"); exit(EXIT_FAILURE))
    for (i = 0; i < config->k; i++) {
        cashier_state starting_state = sleeping;
        if (i < config->ka)
            starting_state = active;
        cashiers_args[i] = alloc_cashier(i, gs, starting_state, config->kt, config->d, mqueue);
        EQNULL(cashiers_args[i], perror("alloc_cashier"); exit(EXIT_FAILURE))
    }

    //Inizializzo il direttore senza farlo partire
    manager = alloc_manager(gs, config->s1, config->s2, config->ka, mqueue, cashiers_args, config->k);
    EQNULL(manager, perror("alloc_manager"); exit(EXIT_FAILURE))

    //Imposto l'handler e faccio partire il thread. Da questo momento lui prenderà tutti i segnali
    err = setup_signal_handling(&handler_thread, mqueue, gs, cashiers_args, config->k);
    NOTZERO(err, perror("setup_signal_handling"); exit(EXIT_FAILURE))

    //Faccio partire i cassieri
    cashiers = cashiers_create(cashiers_args, gs, config->k);
    EQNULL(cashiers, perror("cashiers_create"); exit(EXIT_FAILURE))

    //Faccio partire il direttore
    PTH(err, pthread_create(&manager_thread, NULL, &manager_fun, manager), perror("manager pthread create"); exit(EXIT_FAILURE))

    //Faccio partire i clienti
    clients = clients_create(gs, config->c, config->t, config->p, cashiers_args, config->k);
    EQNULL(clients, perror("clients_create"); exit(EXIT_FAILURE))

    printf(MESSAGE_STORE_IS_OPEN);
    //Gestisco le entrate e le uscite del supermercato
    err = manage_entrance(gs, &closing_state, config->c, config->e);
    NOTZERO(err, perror("Main"); exit(EXIT_FAILURE))

    if (closing_state == closed) {
        printf(MESSAGE_STORE_IS_CLOSING);
        printf("Tutti i clienti in coda verranno serviti prima di chiudere definitivamente.\n");
    } else if (closing_state == closed_fast) {
        printf(MESSAGE_STORE_IS_CLOSING);
        printf("Tutti i clienti in coda verranno fatti uscire immediatamente.\n");
    }

    //Alloco memoria per ottenere le statistiche di ogni thread cliente e cassiere
    clients_stats = (client_thread_stats**) malloc(sizeof(client_thread_stats*)*config->c);
    EQNULL(clients_stats, perror("malloc clients stats"); exit(EXIT_FAILURE))
    cashiers_stats = (cashier_thread_stats**) malloc(sizeof(cashier_thread_stats*)*config->k);
    EQNULL(cashiers_stats, perror("malloc cashiers stats"); exit(EXIT_FAILURE))

    //Eseguo la join sui vari threads!
    //join sul thread signal handler
    PTH(err, pthread_join(handler_thread, NULL), perror("join thread handler"); exit(EXIT_FAILURE))
    //join sui clienti
    MINUS1(thread_pool_join(clients, (void**)clients_stats), perror("join clients"); exit(EXIT_FAILURE))
    printf("Clienti terminati\n");
    //join sui cassieri
    MINUS1(thread_pool_join(cashiers, (void**)cashiers_stats), perror("join cashiers"); exit(EXIT_FAILURE))
    printf("Cassieri terminati\n");
    //join sul direttore
    PTH(err, pthread_join(manager_thread, NULL), perror("join thread manager"); exit(EXIT_FAILURE))
    printf("Direttore terminato\n");

    //logging!
    printf("Scrivo il file di log %s\n", config->logfilename);
    logfile = fopen(config->logfilename, "w");
    MINUS1(write_log(logfile, clients_stats, config->c, cashiers_stats, config->k), perror("write log"); exit(EXIT_FAILURE))
    fclose(logfile);

    //cleanup!
    for (i = 0; i < (config->c); i++) {
        destroy_client_thread_stats(clients_stats[i]);
    }
    for (i = 0; i < (config->k); i++) {
        destroy_cashier_thread_stats(cashiers_stats[i]);
    }
    NOTZERO(thread_pool_free(clients), perror("free clients"); exit(EXIT_FAILURE))  //free clienti
    NOTZERO(thread_pool_free(cashiers), perror("free cashiers"); exit(EXIT_FAILURE)) //free cassieri
    MINUS1(destroy_manager_queue(mqueue), perror("manager queue destroy"); exit(EXIT_FAILURE));
    free(cashiers_args);
    free(clients_stats);
    free(cashiers_stats);
    grocerystore_destroy(gs);
    free_config(config);
    return 0;
}

/**
 * Esegue il parsing degli argomenti passati al programma via linea di comando. Ritorna il path del file
 * di configurazione indicato dall'utente oppure il path di default se l'utente non ha specificato nulla.
 * @param argc numero di argomenti
 * @param args gli argomenti passati al programma
 * @return il path del file di configurazione indicato dall'utente oppure il path di default se l'utente non lo ha
 * specificato
 */
char *parseArgs(int argc, char **args) {
    int i = 1;
    while(i < argc && strcmp(args[i], ARG_CONFIG_FILE) != 0) {
        i++;
    }
    i++;
    return i < argc ? args[i]:(char *)DEFAULT_CONFIG_FILE;
}

thread_pool_t *cashiers_create(cashier_t **cashiers_args, grocerystore_t *gs, int size) {
    int i;
    thread_pool_t *cashiers = thread_pool_create(size);
    EQNULL(cashiers, return NULL)

    for (i = 0; i < size; ++i) {
        NOTZERO(thread_create(cashiers, &cashier_fun, cashiers_args[i]), return NULL)
    }
    return cashiers;
}

thread_pool_t *clients_create(grocerystore_t *gs, int size, int t, int p, cashier_t **cashiers_args, size_t no_of_cashiers) {
    int i;
    thread_pool_t *clients = thread_pool_create(size);
    EQNULL(clients, return NULL)

    for (i = 0; i < size; ++i) {
        client_t *client = alloc_client(i, gs, t, p, cashiers_args, no_of_cashiers);
        EQNULL(client, return NULL)

        NOTZERO(thread_create(clients, &client_fun, client), return NULL)
    }
    return clients;
}
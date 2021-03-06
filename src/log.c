#include "../libs/utils/include/utils.h"
#include "../include/log.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Scrive le statistiche di un cliente entrato nel supermercato. Ritorna 0 se la scrittura è avvenuta con successo, -1
 * altrimenti e setta errno. Questa funzione è eseguita per ogni elemento della lista quindi il valore di ritorno è
 * importante per evitare errori in cascata.
 *
 * @param elem elemento della lista, ovvero la statistica di un cliente
 * @param args argomenti aggiuntivi, ovvero il file sul quale scrivere il log
 * @return 0 in caso di successo, -1 altrimenti ed imposta errno
 */
static int write_client_stats(void *elem, void *args);

/**
 * Scrive un valore in secondi con al più 3 cifre decimali sul file descriptor passato. Il valore viene scritto seguito
 * dalla stringa "s". Questa funzione è eseguita per ogni elemento della lista quindi il valore di ritorno è importante
 * per evitare errori in cascata.
 *
 * @param elem elemento della lista, ovvero un valore di tipo long che rappresenta un tempo espresso in millisecondi
 * e la sua conversione in secondi con al più 3 cifre decimali verrà scritta sul log.
 * @param args argomenti aggiuntivi, ovvero il file sul quale scrivere il log
 * @return 0 in caso di successo, -1 altrimenti ed imposta errno
 */
static int print_ms(void *elem, void *args);

/**
 * Aggiorna il log con il tempo di apertura della cassa.
 *
 * @param cassa_log puntatore al log della cassa
 * @return 0 in caso di successo, -1 altrimenti ed imposta errno
 */
static int push_cassa_opening_time(cassa_log_t *cassa_log);

/** Statistiche di un cliente entrato nel supermercato */
typedef struct {
    int id;             //identificatore univoco del cliente
    int products;       //numero di prodotti acquistati
    long time_in_store; //tempo di permanenza nel supermercato espresso in millisecondi
    long time_in_queue; //tempo di attesa in coda espresso in millisecondi
    int queue_counter;  //quante volte il cliente ha cambiato coda
} client_stats_t;

int log_client_stats(list_t *client_log, int id, int prod, long time_instore, long time_inqueue, int queuecounter) {
    client_stats_t *stats = (client_stats_t*) malloc(sizeof(client_stats_t));
    EQNULL(stats, return -1)
    stats->id = id;
    stats->products = prod;
    stats->time_in_store = time_instore;
    stats->time_in_queue = time_inqueue;
    stats->queue_counter = queuecounter;

    MINUS1(push(client_log, stats), return -1)
    return 0;
}

cassa_log_t *alloc_cassa_log(size_t id) {
    cassa_log_t *log = (cassa_log_t*) malloc(sizeof(cassa_log_t));
    EQNULL(log, return NULL)
    log->id = id;
    log->closed_counter = 0;
    log->products_counter = 0;
    EQNULL(log->served = list_create(), return NULL)
    EQNULL(log->opened = list_create(), return NULL)
    log->open_start.tv_sec = 0;
    log->open_start.tv_nsec = 0;
    return log;
}

int destroy_cassa_log(cassa_log_t *log) {
    MINUS1(list_destroy(log->served, &free), return -1)
    MINUS1(list_destroy(log->opened, &free), return -1)
    free(log);
    return 0;
}

int log_client_served(cassa_log_t *cassa_log, long time, int products) {
    long *value = (long*) malloc(sizeof(long));
    *value = time;
    EQNULL(value, return -1)
    MINUS1(push(cassa_log->served, value), return -1)
    cassa_log->products_counter += products;
    return 0;
}

int log_cassa_open(cassa_log_t *cassa_log) {
    if ((cassa_log->open_start).tv_sec == 0 && (cassa_log->open_start).tv_nsec == 0)
        MINUS1(clock_gettime(CLOCK_MONOTONIC, &(cassa_log->open_start)), return -1)
    return 0;
}

int log_cassa_closed(cassa_log_t *cassa_log) {
    cassa_log->closed_counter++;
    //Se ho preso il tempo significa che è stata aperta quindi calcolo tempo di apertura
    MINUS1(push_cassa_opening_time(cassa_log), return -1)
    return 0;
}

int log_cassa_store_closed(cassa_log_t *cassa_log) {
    MINUS1(push_cassa_opening_time(cassa_log), return -1)
    return 0;
}

int write_log(char *filename, list_t *clients_stats, cassa_log_t **cassieri_stats, int k) {
    int i, served_clients = 0, total_products = 0, noproducts;  //il numero di clienti serviti, il numero di prodotti acquistati
    FILE *out_file;
    list_t *served, *opened;
    //Apro il file di log
    EQNULL(out_file = fopen(filename, "w"), return -1);
    //Scrivo log accumulato dai clienti
    MINUS1(foreach(clients_stats, &write_client_stats, out_file), return -1)
    //Scrivo log accumulato dai cassieri
    for (i = 0; i < k; i++) {
        served = cassieri_stats[i]->served;
        opened = cassieri_stats[i]->opened;

        fprintf(out_file, "[Cassiere %ld] clienti serviti: %d, prodotti elaborati: %d, chiusure: %d",
                (cassieri_stats[i])->id, served->size, cassieri_stats[i]->products_counter, cassieri_stats[i]->closed_counter);
        if (opened->size > 0) { //Se la cassa è stata aperta almeno una volta
            fprintf(out_file, ", periodi di apertura cassa:");
            MINUS1(foreach(opened, &print_ms, out_file), return -1)
        }
        if (served->size > 0) { //Se è stato servito almeno un cliente
            fprintf(out_file, ", tempi di servizio dei clienti serviti:");
            MINUS1(foreach(served, &print_ms, out_file), return -1)
        }
        fprintf(out_file, "\n");

        total_products += cassieri_stats[i]->products_counter;
        served_clients += served->size;
    }
    //Clienti usciti senza fare acquisti = clienti entrati - clienti serviti
    noproducts = clients_stats->size - served_clients;

    //Scrivo le statistiche generali
    fprintf(out_file, "Numero di clienti entrati nel supermercato: %d\n", clients_stats->size);
    fprintf(out_file, "Numero di clienti usciti senza acquisti: %d\n", noproducts);
    fprintf(out_file, "Numero di clienti serviti: %d\n", served_clients);
    fprintf(out_file, "Numero di prodotti acquistati: %d\n", total_products);

    fclose(out_file);
    return 0;
}

int compare_client_stats(void *first, void *second) {
    return ((client_stats_t*) first)->id - ((client_stats_t*) second)->id;
}

static int push_cassa_opening_time(cassa_log_t *cassa_log) {
    long *time;
    if ((cassa_log->open_start).tv_sec != 0 || (cassa_log->open_start).tv_nsec != 0) {
        EQNULL(time = (long *) malloc(sizeof(long)), return -1)
        MINUS1(*time = elapsed_time(&(cassa_log->open_start)), return -1)
        MINUS1(push(cassa_log->opened, time), return -1)
        (cassa_log->open_start).tv_nsec = 0;
        (cassa_log->open_start).tv_sec = 0;
    }
    return 0;
}

static int write_client_stats(void *elem, void *args) {
    client_stats_t *cl_stats = (client_stats_t*) elem;
    double time_in_store = (float)(cl_stats->time_in_store) / 1000;
    double time_in_queue = (float)(cl_stats->time_in_queue) / 1000;
    fprintf((FILE*)args, "[Cliente %d] tempo di permanenza: %.3fs, prodotti acquistati: %d, code cambiate: %d, tempo in coda: %.3fs\n", cl_stats->id, time_in_store, cl_stats->products, cl_stats->queue_counter, time_in_queue);
    return 0;
}

static int print_ms(void *elem, void *args) {
    long *value = (long*) elem;
    double seconds = (double)(*value)/1000;
    fprintf((FILE*)args, " %.3fs", seconds);
    return 0;
}
/**
 * Header file con tutti i tipi utilizzati dal processo supermercato
 */

#ifndef STORETYPES_H
#define STORETYPES_H

#include "log.h"
#include <pthread.h>

typedef enum {
    open_state,       //Il supermercato è aperto. I clienti possono entrare
    closed_state,     //Il supermercato è chiuso. I clienti non possono entrare mentre quelli già dentro devono finire gli acquisti
    closed_fast_state //Il supermercato è chiuso. I clienti non possono entrare e quelli dentro devono subito uscire
} store_state;

/**
 * Struttura dati base del supermercato la quale contiene lo stato del supermercato e viene utilizzata anche per la
 * gestione delle entrate e delle uscite.
 */
typedef struct {
    pthread_mutex_t store_mtx;
    store_state state;          //Stato del supermercato
    pthread_cond_t entrance;    //I thread clienti rimangono in attesa su questa condition variable. Vengono svegliati quando ci sono C-E clienti dentro al supermercato
    int clients_outside;        //Numero di clienti usciti dal supermercato
    int group_size;             //Parametro e
    int can_enter;              //Vale tanto quanto il numero di clienti che possono entrare
    int clients_counter;        //Numero di clienti entrati nel supermercato
} store_t;

/**
 * Struttura dati utilizzata per interfacciare cassieri e clienti. Utile per information hiding in quanto il cliente
 * non può accedere direttamente al cassiere ed il cassiere può accedere solo a ciò che è per lui fondamentale, ovvero
 * la condition variable sulla quale il cliente sta attendendo mentre si trova in coda ed il numero di prodotti che il
 * cliente vuole acquistare.
 */
typedef struct client_in_queue {
    pthread_cond_t waiting; //variabile di condizione sulla quale il cliente aspetta di essere servito
    int products;           //numero di prodotti acquistati
    int served;             //vale 1 se è stato servito, 0 altrimenti
    int processing;         //vale 1 se il cassiere sta servendo il cliente ma non ha ancora finito, 0 altrimenti
    int is_enqueued;        //vale 1 se il cliente è in coda, 0 altrimenti
    struct client_in_queue *next;   //cliente successivo
    struct client_in_queue *prev;   //cliente precedente
} client_in_queue_t;

/**
 * Struttura dati di una cassa del supermercato. Il costo di una cassa indica quanto è conveniente accodarsi alla cassa.
 * Più il costo è alto e meno è la cassa conveniente. La migliore cassa, quindi, è quella che in un dato momento ha il
 * costo più basso. Il costo dipende dal tempo di servizio del cassiere in relazione al numero di clienti in coda e a
 * quanti prodotti deve processare in totale.
 */
typedef struct {
    pthread_cond_t noclients;   //il cassiere aspetta su questa variabile di condizione quando non ci sono clienti
    client_in_queue_t *head;
    client_in_queue_t *tail;
    int size;   //quanti clienti ci sono in coda
    int cost;   //quanto è il costo della coda se ci si dovessere accodare
} cassa_queue_t;

/**
 * Struttura dati di un cassiere.
 */
typedef struct {
    size_t id;                  //identificatore univoco del cassiere
    store_t *store;
    cassa_queue_t *queue;             //clienti in coda
    pthread_mutex_t mutex;
    pthread_cond_t noclients;   //il cassiere aspetta su questa variabile di condizione quando non ci sono clienti
    pthread_cond_t waiting;     //il cassiere attende su questa variabile di condizione quando la cassa viene chiusa
    cassa_log_t *cassa_log;     //log della cassa
    int isopen;
    int product_service_time;   //quanto impiega a gestire un singolo prodotto
    int fixed_service_time;     //tempo fisso per la gestione di un cliente
    int interval;               //intervallo tra una notifica ed un'altra. espresso in millisecondi
} cassiere_t;

/**
 * Struttura dati di un cliente
 */
typedef struct {
    size_t id;
    pthread_mutex_t mutex;
    pthread_cond_t exit_permission;  //Il thread cliente rimane attesa su questa condition variable per aspettare il permesso di uscita
    int can_exit;
    store_t *store;
    cassiere_t **casse; //Tutte le casse del supermercato
    int k;  //massimo numero di casse del supermercato
    int t;  //tempo massimo per acquistare prima di mettersi in una coda
    int p;  //numero massimo di prodotti che acquista
    int s;  //ogni quanto tempo il cliente decide se cambiare cassa
} client_t;

#endif //STORETYPES_H

#ifndef STORETYPES_H
#define STORETYPES_H

#include <pthread.h>
#include "../include/utils.h"

typedef enum {
    open_state,       //Il supermercato è aperto. I clienti possono entrare
    closed_state,     //Il supermercato è chiuso. I clienti non possono entrare mentre quelli già dentro devono finire gli acquisti
    closed_fast_state //Il supermercato è chiuso. I clienti non possono entrare e quelli dentro devono subito uscire
} store_state;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t entrance;    //I thread clienti rimangono in attesa su questa condition variable. Vengono svegliati quando ci sono C-E clienti dentro al supermercato
    store_state state;  //stato del supermercato
    int clients_inside; //numero di clienti dentro al supermercato
    int max_clients;    //parametro c
    int group_size;     //parametro e
    int can_enter;          //vale tanto quanto il numero di clienti che possono entrare.
    size_t total_clients;   //contatore per dare un nuovo identificatore ai clienti che entrano nel supermercato
} store_t;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t exit_permission;  //Il thread cliente rimane attesa su questa condition variable per aspettare il permesso di uscita
    int can_exit;
    size_t id;
    store_t *store;
    //cashier_t **casse;
    int k;  //massimo numero di casse del supermercato
    int t;  //tempo massimo per acquistare prima di mettersi in una coda
    int p;  //numero massimo di prodotti che acquista
    int s;  //ogni quanto tempo il cliente decide se cambiare cassa
    safe_fd_t *sfd;  //descrittore del file utilizzato per comunicare con il direttore. Le scritture sono thread safe
} client_t;

#endif //STORETYPES_H

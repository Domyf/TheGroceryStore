#include "../include/store.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>

//#define DEBUGSTORE

store_t *store_create(size_t c, size_t e) {
    int err;
    store_t *store = (store_t*) malloc(sizeof(store_t));
    EQNULL(store, return NULL)

    store->state = open_state;
    store->clients_inside = 0;
    store->max_clients = c;
    store->group_size = e;
    store->can_enter = c;   //All'inizio ne vengono fatti entrare c, ovvero tutti i clienti entrano contemporaneamente
    store->total_clients = 0;

    PTH(err, pthread_mutex_init(&(store->mutex), NULL), return NULL)
    PTH(err, pthread_cond_init(&(store->entrance), NULL), return NULL)

    return store;
}

int store_destroy(store_t *store) {
    int err;
    PTH(err, pthread_mutex_destroy(&(store->mutex)), return -1)
    PTH(err, pthread_cond_destroy(&(store->entrance)), return -1)
    free(store);
    return 0;
}

int get_store_state(store_t *store, store_state *state) {
    int err;
    PTH(err, pthread_mutex_lock(&(store->mutex)), return -1)
    *state = store->state;
    PTH(err, pthread_mutex_unlock(&(store->mutex)), return -1)
    return 0;
}

int close_store(store_t *store, store_state closing_state) {
    int err;
    PTH(err, pthread_mutex_lock(&(store->mutex)), return -1)
    store->state = closing_state;
    store->can_enter = 0;
    PTH(err, pthread_cond_broadcast(&(store->entrance)), return -1)
    PTH(err, pthread_mutex_unlock(&(store->mutex)), return -1)
    return 0;
}

int enter_store(store_t *store) {
    int err, client_id = 0;
    PTH(err, pthread_mutex_lock(&(store->mutex)), return -1)
    while(ISOPEN(store->state) && store->can_enter == 0) {
        PTH(err, pthread_cond_wait(&(store->entrance), &(store->mutex)), return -1)
    }
    //Entro se è aperto altrimenti sono stato risvegliato perchè devo terminare
    if (ISOPEN(store->state)) {
        (store->can_enter)--;
        (store->clients_inside)++;
        (store->total_clients)++;
        client_id = store->total_clients;
#ifdef DEBUGSTORE
        printf("Entro, ne possono entrare altri %d\n", store->can_enter);
#endif
    }
    PTH(err, pthread_mutex_unlock(&(store->mutex)), return -1)
    return client_id;
}

int exit_store(store_t *store) {
    int err;
    PTH(err, pthread_mutex_lock(&(store->mutex)), return -1);
    (store->clients_inside)--;
    if (store->can_enter == 0 && store->clients_inside == store->max_clients - store->group_size) {
        store->can_enter = store->group_size;
        PTH(err, pthread_cond_broadcast(&(store->entrance)), return -1)
#ifdef DEBUGSTORE
        printf("Ci sono %d clienti nel supermercato. Faccio entrare altri %d clienti\n", store->clients_inside, store->group_size);
#endif
    }
    PTH(err, pthread_mutex_unlock(&(store->mutex)), return -1)
    return 0;
}
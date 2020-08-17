#define DEBUGGING 0
#include <stdlib.h>
#include <stdio.h>
#include "../include/notifier.h"
#include "../include/utils.h"
#include "../include/store.h"

void *notifier_thread_fun(void *args) {
    int err, queue_len;
    notifier_t *no = (notifier_t*) args;
    cassiere_t *ca = no->cassiere;

    //Attendo l'intervallo
    MINUS1(msleep(ca->interval), perror("msleep"); return NULL)

    PTH(err, pthread_mutex_lock(&(no->mutex)), perror("lock"); return NULL)
    while(no->state != notifier_quit) {
        //Aspetto di essere attivato dal cassiere
        while(no->state == notifier_pause) {
            PTH(err, pthread_cond_wait(&(no->paused), &(no->mutex)), perror("cond wait"); return NULL)
        }
        //Controllo se sono stato attivato perchè il supermercato sta chiudendo
        if (no->state == notifier_run) {
            PTH(err, pthread_mutex_unlock(&(no->mutex)), perror("unlock"); return NULL)

            //Prendo la lunghezza della coda
            PTH(err, pthread_mutex_lock(&(ca->mutex)), perror("lock"); return NULL)
            queue_len = (ca->queue)->size;
            PTH(err, pthread_mutex_unlock(&(ca->mutex)), perror("unlock"); return NULL)

            //Invio al direttore il numero di clienti in coda
            MINUS1(notify(ca->id, queue_len), perror("notify"))

            DEBUG("Notificatore %ld: ho inviato una notifica\n", ca->id);
            //Attendo l'intervallo
            MINUS1(msleep(ca->interval), perror("msleep"); return NULL)

            PTH(err, pthread_mutex_lock(&(no->mutex)), perror("lock"); return NULL)
        }
    }
    PTH(err, pthread_mutex_unlock(&(no->mutex)), perror("unlock"); return NULL)
    DEBUG("Notificatore %ld: termino\n", ca->id);
    return 0;
}

notifier_t *alloc_notifier(cassiere_t *cassiere, int start_notify) {
    int err;
    notifier_t *notifier = (notifier_t*) malloc(sizeof(notifier_t));
    EQNULL(notifier, return NULL)
    notifier->cassiere = cassiere;
    PTH(err, pthread_mutex_init(&(notifier->mutex), NULL), return NULL)
    PTH(err, pthread_cond_init(&(notifier->paused), NULL), return NULL)
    notifier->state = start_notify? notifier_run:notifier_pause;
    return notifier;
}

int destroy_notifier(notifier_t *notifier) {
    int err;
    PTH(err, pthread_mutex_destroy(&(notifier->mutex)), return -1)
    PTH(err, pthread_cond_destroy(&(notifier->paused)), return -1)
    free(notifier);
    return 0;
}

int set_notifier_state(notifier_t *no, notifier_state new_state) {
    int err;
    PTH(err, pthread_mutex_lock(&(no->mutex)), return -1)
    no->state = new_state;
    PTH(err, pthread_cond_signal(&(no->paused)), return -1)
    PTH(err, pthread_mutex_unlock(&(no->mutex)), return -1)
    return 0;
}
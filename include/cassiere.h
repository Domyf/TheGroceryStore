#ifndef CASSIERE_H
#define CASSIERE_H

#include "storetypes.h"

void *cassiere_thread_fun(void *args);

cassiere_t *alloc_cassiere(size_t id, store_t *store, int fd, pthread_mutex_t *fd_mtx, int product_service_time, int interval);

int cassiere_destroy(cassiere_t *cassiere);

#endif //CASSIERE_H

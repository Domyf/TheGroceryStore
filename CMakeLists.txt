cmake_minimum_required(VERSION 3.10)
project(TheGroceryStore C)

set(CMAKE_C_STANDARD 99)

add_executable(TheGroceryStore src/direttore.c src/config.c include/config.h libs/utils/src/utils.c libs/utils/include/utils.h src/supermercato.c src/sig_handling.c include/sig_handling.h src/af_unix_conn.c include/af_unix_conn.h src/scfiles.c include/scfiles.h libs/list/src/list.c libs/list/include/list.h include/storetypes.h src/store.c include/store.h src/threadpool.c include/threadpool.h src/client.c include/client.h src/cassiere.c include/cassiere.h src/notifier.c include/notifier.h src/log.c include/log.h src/client_in_queue.c include/client_in_queue.h src/cassa_queue.c include/cassa_queue.h)
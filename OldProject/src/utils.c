#include "utils.h"
#include <stdio.h>

#define LONG1E9 1000000000L //1e9

int msleep(int milliseconds) {
    struct timespec req = {MS_TO_SEC(milliseconds), (milliseconds%1000)*1000000}, rem = {0, 0};
    int res;
    do {
        rem.tv_sec = 0;
        rem.tv_nsec = 0;
        res = nanosleep(&req, &rem);
        req = rem;
    } while (res == EINTR);

    return res;
}

long get_elapsed_milliseconds(struct timespec start, struct timespec end) {
    struct timespec diff = {end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec};
    if (diff.tv_nsec < 0) {
        diff.tv_sec -= 1;
        diff.tv_nsec += LONG1E9;
    }

    return (diff.tv_sec * 1000.0) + (diff.tv_nsec/1000000.0);
}

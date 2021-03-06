#include "../include/utils.h"
#include <stdlib.h>

#define LONG1E9 1000000000L //1e9

int msleep(int milliseconds) {
    struct timespec req = {MS_TO_SEC(milliseconds), MS_TO_NANOSEC(milliseconds)}, rem = {0, 0};
    int res;
    do {
        rem.tv_sec = 0;
        rem.tv_nsec = 0;
        res = nanosleep(&req, &rem);
        req = rem;
    } while (res == EINTR);

    return res;
}

long elapsed_time(struct timespec *start) {
    struct timespec now = {0,0};
    MINUS1(clock_gettime(CLOCK_MONOTONIC, &now), return -1)
    struct timespec diff = {now.tv_sec - start->tv_sec, now.tv_nsec - start->tv_nsec};
    if (diff.tv_nsec < 0) {
        diff.tv_sec -= 1;
        diff.tv_nsec += LONG1E9;
    }

    return diff.tv_sec * 1000L + diff.tv_nsec / 1000000L;
}

int probability(unsigned int seed, int percent) {
    return RANDOM(seed, 0, 100) < percent;
}
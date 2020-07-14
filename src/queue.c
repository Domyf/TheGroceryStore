/**
 * Implementazione di una unbounded queue FIFO.
 */

#include "queue.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static int internal_foreach(node_t *node, int (*fun)(void*));

queue_t *queue_create(void) {
    queue_t *queue = (queue_t*) malloc(sizeof(queue_t));
    EQNULL(queue, return NULL)
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int queue_destroy(queue_t *queue) {
    clear(queue);
    free(queue);
    return 0;
}

int push(queue_t *queue, void *elem) {
    node_t *node = (node_t*) malloc(sizeof(node_t));
    EQNULL(node, return -1)
    node->elem = elem;
    node->prev = NULL;
    node->next = queue->head;
    if (queue->head == NULL) {
        queue->tail = node;
    } else {
        (queue->head)->prev = node;
    }

    queue->head = node;
    (queue->size)++;
    return 0;
}

void *pop(queue_t *queue) {
    void *tailElem = NULL;
    node_t *tailNode;
    node_t *tailPrevNode;
    if (queue->size > 0) {
        tailNode = (queue->tail);
        tailPrevNode = (queue->tail)->prev;
        tailElem = (queue->tail)->elem;
        queue->tail = tailPrevNode;
        if (queue->size == 1) {
            queue->head = NULL;
        } else {
            tailPrevNode->next = NULL;
        }
        (queue->size)--;
        free(tailNode);
    }
    return tailElem;
}

int foreach(queue_t *queue, int (*fun)(void*)) {
    return internal_foreach(queue->tail, fun);
}

static int internal_foreach(node_t *node, int (*fun)(void*)) {
    if (node != NULL) {
        MINUS1(fun(node->elem), return -1)
        return internal_foreach(node->prev, fun);
    }
    return 0;
}

void clear(queue_t *queue) {
    node_t *curr;

    while(queue->size > 0) {
        curr = pop(queue);
        free(curr);
    }
}
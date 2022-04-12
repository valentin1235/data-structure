#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "utils.h"

typedef struct queue {
    int list[SIZE];
    size_t front;
    size_t back;
    size_t count;
} queue_t;

int enqueue(queue_t* queue, int value);

int dequeue(queue_t* queue);

#endif /* QUEUE_H */

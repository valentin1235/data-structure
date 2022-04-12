#include <assert.h>
#include <stdio.h>

#include "queue.h"

int enqueue(queue_t* queue, int value)
{
    if (queue->count >= SIZE) {
        return FALSE;
    }

    

    queue->list[queue->front++ % SIZE] = value; 
    ++queue->count;

    return TRUE;
}

int dequeue(queue_t* queue)
{
    assert(queue->count > 0);

    --queue->count;
    return queue->list[queue->back++ % SIZE];
}

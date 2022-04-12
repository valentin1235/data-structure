#ifndef MYSTACK_H
#define MYSTACK_H

#include "utils.h"


typedef struct mystack {
    int list[SIZE];
    int count;
} mystack_t;

int push(mystack_t* stack, int value);
int pop(mystack_t* stack);

#endif /* MYSTACK_H */

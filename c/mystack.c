#include <stdio.h>
#include <assert.h>

#include "mystack.h"


int push(mystack_t* stack, int value)
{
    if (stack->count >= SIZE) {
        return FALSE;
    }
    
    stack->list[stack->count++] = value;
    return TRUE;
}

int pop(mystack_t* stack)
{
    assert(stack->count > 0);

    

    return stack->list[--stack->count];
}

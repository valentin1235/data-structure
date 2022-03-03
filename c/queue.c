#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

enum { MAX_NUMS = 5 };

static s_nums[MAX_NUMS];
static s_front = 0;
static s_back = 0;
static s_num_count = 0;

void enqueue(int n)
{
    assert(s_num_count < MAX_NUMS);

    s_nums[s_back] = n;

    s_back = (s_back + 1) % MAX_NUMS;
    ++s_num_count;
    
    printf("+ enqueue %d\n", s_back);
}

int dequeue(void)
{
    int result;
    assert(s_num_count > 0);

    result = s_nums[s_front];

    s_front = (s_front + 1) % MAX_NUMS;
    --s_num_count;

    printf("- dequeue %d\n", s_front);

    return result;
}

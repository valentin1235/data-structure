#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hashset.h"
#include "utils.h"


hashset_t* init_hashset_malloc(size_t size)
{
    hashset_t* hashset;
    size_t i;

    hashset = malloc(sizeof(hashset_t));

    hashset->list = malloc(size * sizeof(int));
    for (i = 0; i < size; ++i) {
        hashset->list[i] = __INT_MAX__;
    }

    hashset->size = size;

    return hashset;
}

int has_value(hashset_t* hashset, int value)
{
    size_t size = hashset->size;
    size_t start_index = value % size;
    size_t i = start_index;

    do {
        if (hashset->list[start_index] == value) {
            return TRUE;
        }
        i = (i + 1) % size;
    } while (i != start_index);

    return FALSE;

    
}

int add_value(hashset_t* hashset, int value)
{
    size_t size = hashset->size;
    size_t start_index = value % size;
    size_t i = start_index;

    do {
        if (hashset->list[i] == __INT_MAX__) {
            hashset->list[i] = value;

            return TRUE;
        }
        i = (i + 1) % size;
    } while (i != start_index);
    
    return FALSE;
}

int remove_hash_value(hashset_t* hashset, int value)
{
    size_t size = hashset->size;
    size_t start_index = value % size;
    size_t i = start_index;

    do {
        if (hashset->list[i] == value) {
            hashset->list[i] = __INT_MAX__;

            return TRUE;
        }
        i = (i + 1) % size;
    } while (i == start_index);

    return FALSE;
}

void destroy_hashset(hashset_t* hashset)
{
    free(hashset->list);
    free(hashset);
}

void print_set(hashset_t* hashset)
{
    size_t size = hashset->size;
    size_t i;
    size_t count = 0;

    printf("[ ");
    for (i = 0; i < size; ++i) {
        if (hashset->list[i] != __INT_MAX__) {
            printf("%d, ", hashset->list[i]);
            ++count;
        }
    }
    printf("] - size : %lu\n", count);
}

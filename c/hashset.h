#ifndef HASHSET_H
#define HASHSET_H

#include <stdio.h>

typedef struct hashset {
    size_t size;
    int* list;
} hashset_t;

hashset_t* init_hashset_malloc(size_t size);
int has_value(hashset_t* hashset, int value);
int add_value(hashset_t* hashset, int value);
int remove_hash_value(hashset_t* hashset, int value);
void destroy_hashset(hashset_t* hashset);
void print_set(hashset_t* hashset);

#endif /* HASHSET_H */

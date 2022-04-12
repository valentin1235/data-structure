#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>

typedef struct linknode {
    int value;
    struct linknode* next;
} linknode_t;

int insert_ordered(linknode_t** head, int value);
int insert_front(linknode_t** head, int value);
int remove_last(linknode_t** head);
int remove_at(linknode_t** head, size_t index);
int remove_value(linknode_t** head, int value);
int get_at(linknode_t** head, size_t index);
void destroy_linkedlist(linknode_t* head);
void print_node(linknode_t* head);


#endif /* LINKEDLIST_H */

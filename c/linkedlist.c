#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct node {
    int val;
    struct node* next;
} node_t;

/* static variables and functions */
static node_t* s_head = NULL;
static node_t* s_tail = NULL;
static size_t s_count = 0;

static int is_empty(void)
{
    return s_head == NULL && s_tail == NULL;
}

static node_t* get_node(size_t index)
{
    size_t i;
    node_t* p = s_head;
    
    assert(index < s_count);

    for (i = 0; i < index; ++i) {
        p = p->next;
    }

    return p;
}

/* main features */
void add_last(int v) {
    node_t* node;

    node = malloc(sizeof(node_t));

    if (is_empty()) {
        add_first(v);
        return;
    }

    node->val = v;
    node->next = NULL;

    s_tail->next = node;
    s_tail = node;
    ++s_count;
}

void add_first(int v)
{
    node_t* node;

    node = malloc(sizeof(node_t));
    node->val = v;

    if (is_empty()) {
        s_tail = node;
        node->next = NULL;
    } else {
        node->next = s_head;
    }

    s_head = node;
    ++s_count;
}

void add_at(size_t index, int v)
{
    node_t* node;
    node_t* before_node;
    
    assert(index < s_count);

    if (index == s_count - 1) {
        add_last(v);
        return;
    }

    before_node = get_node(index - 1);

    node = malloc(sizeof(node_t));
    node->val =  v;
    node->next = before_node->next;

    before_node->next = node;
    ++s_count;
}

void remove_last()
{
    node_t* before_tail = get_node(s_count - 2);

    before_tail->next = NULL;
    s_tail = before_tail;
}

void remove_first()
{
    node_t* removed;

    removed = s_head;

    s_head = s_head->next;

    free(removed);
    --s_count;
}

void remove_at(size_t index)
{
    node_t* removed;
    node_t* before_node;
    
    assert(index < s_count);

    if (index == 0) {
        remove_first();
        return;
    } else if (index == s_count - 1) {
        remove_last();
        return;
    }

    before_node = get_node(index - 1);

    removed = before_node->next;

    before_node->next = before_node->next->next;

    free(removed);
    --s_count;
}

void destroy_list()
{
    node_t* node = s_head;
    node_t* to_be_removed;

    while (node != NULL) {
        to_be_removed = node;
        node = node->next;

        free(to_be_removed);
    }

    s_head = NULL;
    s_tail = NULL;
}

int get_value(size_t index)
{
    size_t i;
    node_t* p = s_head;
    
    assert(index < s_count);

    return get_node(index)->val;
}

void print_node(void)
{
    node_t* p = s_head;

    printf("{ ");
    while (p != NULL) {
        printf("%d, ", p->val);
        p = p->next;
    }
    printf(" }\n");
}

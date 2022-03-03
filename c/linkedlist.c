#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct node {
    int val;
    struct node* next;
} node_t;

static node_t* s_head = NULL;
static node_t* s_tail = NULL;
static size_t s_count = 0;

static int is_empty(void)
{
    return s_head == NULL && s_tail == NULL;
}

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
    size_t i;
    node_t* p = s_head;
    node_t* node;
    
    assert(index < s_count);

    node = malloc(sizeof(node_t));

    for (i = 0; i < index - 1; ++i) {
        p = p->next;
    }

    node->val =  v;
    node->next = p->next;

    p->next = node;
    ++s_count;
}

void remove_last()
{
    remove_at(s_count - 1);
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
    int i;
    int before_index = index - 1;
    node_t* p = s_head;
    node_t* removed;
    
    assert(index < s_count);

    for (i = 0; i < before_index; ++i) {
        p = p->next;
    }

    removed = p->next;

    p->next = p->next->next;

    free(removed);
    --s_count;
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

int get_value(size_t index)
{
    size_t i;
    node_t* p = s_head;
    
    assert(index < s_count);

    for (i = 0; i < index; ++i) {
        p = p->next;
    }

    return p->val;
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

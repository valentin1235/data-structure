#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "linkedlist.h"
#include "utils.h"

int insert_ordered(linknode_t** head, int value)
{
    linknode_t** pp = head;
    linknode_t* new_linknode;

    new_linknode = malloc(sizeof(linknode_t));
    new_linknode->value = value;

    while (*pp != NULL) {
        if ((*pp)->value > new_linknode->value) {
            break;
        }
        pp = &(*pp)->next;
    }

    new_linknode->next = *pp;
    *pp = new_linknode;

    return TRUE;
}

int insert_front(linknode_t** head, int value)
{
    linknode_t* new_linknode;

    new_linknode = malloc(sizeof(linknode_t));
    new_linknode->value = value;

    new_linknode->next = *head;
    *head = new_linknode;

    return TRUE;
}

int remove_last(linknode_t** head)
{
    linknode_t** pp = head;

    if (*head == NULL) {
        return FALSE;
    }

    while ((*pp)->next != NULL) {
        pp = &(*pp)->next;
    }

    free(*pp);
    *pp = NULL;

    return TRUE;
}

int remove_at(linknode_t** head, size_t index)
{
    linknode_t** pp = head;
    size_t i;

    if (head == NULL) {
        return FALSE;
    }

    for(i = 0; i < index; ++i) {
        pp = &(*pp)->next;
    }

    {
        linknode_t* next = (*pp)->next;
        free(*pp);
        *pp = next;
    }

    return TRUE;
}

int remove_value(linknode_t** head, int value)
{
    linknode_t** pp = head;
    while (*pp != NULL) {
        if ((*pp)->value == value) {
            linknode_t* next = (*pp)->next;
            free(*pp);
            *pp = next;
            break;
        }
        pp = &(*pp)->next;
    }

    return TRUE;
}

int get_at(linknode_t** head, size_t index)
{
    linknode_t** pp = head;
    size_t i;

    assert(head != NULL);

    for (i = 0; i < index; ++i) {
        pp = &(*pp)->next;
    }

    return (*pp)->value;
}


void destroy_linkedlist(linknode_t* head)
{
    linknode_t* p = head;

    while(p != NULL) {
        linknode_t* next = p->next;
        free(p);
        p = next;
    }
}

void print_node(linknode_t* head)
{
    linknode_t* p = head;

    printf("[ ");
    while (p != NULL) {
        printf("%d, ", p->value);
        p = p->next;
    }
    puts("]");
}

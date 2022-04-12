#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mystack.h"
#include "queue.h"
#include "linkedlist.h"
#include "hashmap.h"
#include "hashset.h"

int hash_func(const char* str);

static void stack_test(void)
{
    mystack_t mystack;
    printf("-------------------------stack_test start!\n");
    mystack.count = 0;

    assert(push(&mystack, 1) == TRUE);
    assert(push(&mystack, 2) == TRUE);
    assert(push(&mystack, 3) == TRUE);
    assert(push(&mystack, 4) == TRUE);
    assert(push(&mystack, 5) == TRUE);
    assert(push(&mystack, 6) == FALSE);

    assert(5 == pop(&mystack));
    assert(4 == pop(&mystack));
    assert(3 == pop(&mystack));
    assert(2 == pop(&mystack));
    assert(1 == pop(&mystack));

}

static void queue_test(void)
{
    queue_t queue;
    printf("-------------------------queue_test start!\n");
    queue.count = 0;
    queue.front = 0;
    queue.back = 0;

    assert(TRUE == enqueue(&queue, 1));
    assert(TRUE == enqueue(&queue, 2));
    assert(TRUE == enqueue(&queue, 3));
    assert(TRUE == enqueue(&queue, 4));
    assert(TRUE == enqueue(&queue, 5));
    assert(FALSE == enqueue(&queue, 6));

    assert(1 == dequeue(&queue));
    assert(2 == dequeue(&queue));
    assert(3 == dequeue(&queue));
    assert(4 == dequeue(&queue));
    assert(5 == dequeue(&queue));

    assert(TRUE == enqueue(&queue, 1));
    assert(TRUE == enqueue(&queue, 2));

    assert(1 == dequeue(&queue));

    assert(TRUE == enqueue(&queue, 3));
    assert(TRUE == enqueue(&queue, 4));
    assert(TRUE == enqueue(&queue, 5));

    assert(2 == dequeue(&queue));
    assert(3 == dequeue(&queue));
    assert(4 == dequeue(&queue));
    assert(5 == dequeue(&queue));
}

static void linkedlist_test(void)
{
    linknode_t* head = NULL;
    printf("-------------------------linkedlist_test start!\n");
    insert_ordered(&head, 1);
    insert_ordered(&head, 2);
    insert_ordered(&head, 3);
    insert_ordered(&head, 4);
    insert_ordered(&head, 5);

    print_node(head);

    remove_last(&head);
    print_node(head);

    printf("%d\n", get_at(&head, 1));

    remove_at(&head, 1);
    print_node(head);

    remove_value(&head, 3);
    print_node(head);

    destroy_linkedlist(head);
}

static void hashmap_test(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(&hash_func, 10);
    printf("-------------------------hashmap_test start!\n");

    add_key(hashmap, "key1", 1);
    add_key(hashmap, "key2", 2);
    add_key(hashmap, "key3", 3);
    add_key(hashmap, "key4", 4);
    print_keys(hashmap);

    assert(TRUE == remove_key(hashmap, "key3"));
    assert(TRUE == remove_key(hashmap, "key1"));
    assert(TRUE == remove_key(hashmap, "key2"));
    assert(TRUE == remove_key(hashmap, "key4"));
    assert(FALSE == remove_key(hashmap, "key123"));
    print_keys(hashmap);

    add_key(hashmap, "key1", 1123);
    assert(get(hashmap, "key1") == 1123);

    destroy_hashmap(hashmap);
}

static void hashset_test(void)
{
    hashset_t* hashset;
    printf("-------------------------hashset_test start!\n");
    hashset = init_hashset_malloc(23);

    add_value(hashset, 10);
    add_value(hashset, 20);
    add_value(hashset, 30);
    add_value(hashset, 40);
    add_value(hashset, 50);
    add_value(hashset, 60);
    add_value(hashset, 70);
    add_value(hashset, 80);
    add_value(hashset, 90);
    add_value(hashset, 100);
    add_value(hashset, 110);
    add_value(hashset, 120);
    add_value(hashset, 1);
    add_value(hashset, 2);
    add_value(hashset, 3);
    add_value(hashset, 4);
    add_value(hashset, 5);
    add_value(hashset, 6);
    add_value(hashset, 7);
    add_value(hashset, 8);
    add_value(hashset, 9);
    add_value(hashset, 10);
    add_value(hashset, 11);
    assert(FALSE == add_value(hashset, 12));
    print_set(hashset);

    remove_hash_value(hashset, 90);
    assert(FALSE == remove_hash_value(hashset, 3123123));
    print_set(hashset);
}

int main(void)
{
    stack_test();
    queue_test();
    linkedlist_test();
    hashmap_test();
    hashset_test();
}

int hash_func(const char* str)
{
    const char* p = str;
    int ret = 0;

    while (*p != '\0') {
        ret += *(p++);
    }

    return ret;
}

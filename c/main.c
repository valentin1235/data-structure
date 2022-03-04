#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "queue.h"
#include "linkedlist.h"
#include "radixsort.h"

static void queue_test(void);
static void linkedlist_test(void);

int main(void)
{
    // radix_sort_test();
    // queue_test();
    linkedlist_test();
    return 0;
}

static void queue_test(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
}

static void linkedlist_test(void)
{
    {
        add_first(31);
        add_first(94);
        add_first(101);
        assert(get_value(0) == 101);
        assert(get_value(1) == 94);
        assert(get_value(2) == 31);

        add_last(62);
        add_last(44);
        assert(get_value(3) == 62);
        assert(get_value(4) == 44);

        add_at(3, 132);
        assert(get_value(3) == 132);
        assert(get_value(4) == 62);

        remove_at(3);
        remove_at(3);
        assert(get_value(3) == 44);

        remove_first();
        assert(get_value(0) == 94);

        remove_last();
        assert(get_value(1) == 31);

        remove_at(0);
        assert(get_value(0) == 31);

        print_node(); /* { 31,  } */

        add_last(1);
        add_last(1);
        add_last(1);
        add_last(1);
        add_last(1);
        add_last(1);

        destroy_list();

        print_node(); /* {  } */
    }

    {
        add_last(1);
        add_last(2);
        add_last(8);
        print_node(); /* { 1, 2, 8,  } */

        add_ordered(6);
        add_ordered(3);
        add_ordered(4);
        add_ordered(5);
        add_ordered(9);
        print_node(); /* { 1, 2, 3, 4, 5, 6, 8, 9,  } */

        assert(get_value(3) == 4);
        assert(get_value(4) == 5);
        assert(get_value(5) == 6);
        assert(get_value(6) == 8);
        assert(get_value(7) == 9);

        destroy_list();
        print_node(); /* {  } */
    }
}

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

void add_last(int n);
void add_first(int n);
void add_at(size_t index, int v);
void remove_last();
void remove_first();
void remove_at(size_t index);
void destroy_list();
void print_node(void);
int get_value(size_t index);

#endif /* LINKEDLIST_H */

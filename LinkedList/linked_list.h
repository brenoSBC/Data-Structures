#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;


LinkedList *ll_create(size_t element_size);
void ll_destroy(LinkedList *list);

bool ll_add_last(LinkedList *list, const void *element);
bool ll_add_at(LinkedList *list, const void *element, const int index);

bool ll_remove_last(LinkedList *list);
// bool ll_remove_at(LinkedList *list);

// void ll_size();
// void ll_is_empty();
// void ll_print(LinkedList *list);



#endif
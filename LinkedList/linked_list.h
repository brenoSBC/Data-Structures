#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;


LinkedList *create(size_t element_size);

void destroy(LinkedList *list);

bool add_last(LinkedList *list, const void *element);

bool remove_last(LinkedList *list);

#endif
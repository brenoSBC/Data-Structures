#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int allocate_memory(Node **node);
   
int create(Node **head, int value);

int add_last(Node **head, int value);

int add_at(Node **head, int value, int index);

int remove_last(Node **head);

#endif
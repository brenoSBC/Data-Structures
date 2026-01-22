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

int remove_at(Node **head, int index);

int destroy_list(Node **head);

int is_empty(Node *head);

int size(Node *head, int *size_var);

int print_list(Node *head);

void print_menu();

void take_return(int flag);

#endif
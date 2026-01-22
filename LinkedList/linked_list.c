#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

int allocate_memory(Node **node) {
    *node = malloc(sizeof(Node));

    if(*node == NULL) {
        return 1;
    }
    return 0;
}

int create(Node **head, int value) {

    if(*head != NULL) {
        printf("\nThere is already a head\n");
        return 1;
    }

    Node *new_node = NULL;

    if(allocate_memory(&new_node) != 0) {
         printf("Error allocating memory\n");
         return 2;
    }

    new_node->value = value;
    *head = new_node;

    return 0;
}

int add_last(Node **head, int value) {

    if(*head == NULL) {
        printf("You must first create a head, there is no head on the ll");
        return 1;
    }

    Node *new_node = NULL;
    if(allocate_memory(&new_node) != 0) {
        printf("\nError allocating memory\n");
        return 2;
    }

    new_node->value = value;
    new_node->next = NULL;

    Node *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    
    return 0;
}

int add_at(Node **head, int value, int index) {

    if(index < 1) {
        printf("Indice invalido");
        return 1;
    }

     if (index == 0) {
        printf("Use a funcao create para criar o primeiro node");
        return 34;
    }

    if(*head == NULL) {
        printf("lista ta vazia use create para criar o primeiro node");
        return 3;
    }
    
    Node *current = *head;
    int local_index = 0;
    while(local_index != index - 1) {
        current = current->next;
        ++local_index;
    }

    Node *new_node = NULL;
    if (allocate_memory(&new_node) != 0) {
        printf("ja sabe");
        return 2;
    }
    new_node->value = value;

    Node *temp = current->next;
    current->next = new_node;
    new_node->next = temp;

    return 0;
}

int remove_last(Node **head) {

    if(*head == NULL) {
        printf("HEAD É NULL ARRUMA ESSA PORRA");
            return 1;
    }

    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return 0;
    }

    Node *current = *head;
  
    while(current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "linked_list.h"

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
    size_t element_size;
};

LinkedList *create(size_t element_size) {

    if(element_size == 0) return NULL;

    LinkedList *list = malloc(sizeof(LinkedList));
    if(list == NULL) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->element_size = element_size;

    return list;
}

void destroy(LinkedList *list) {

    if(list == NULL) return;
    
    Node *current = list->head;
    while(current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}

bool add_last(LinkedList *list, const void *element) {

    if(list == NULL || element == NULL) return false;

    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) return NULL;

    new_node->data = malloc(list->element_size);
    if(new_node->data == NULL){
        free(new_node);
        return false;
    }

    memcpy(new_node->data, element, list->element_size);
    new_node->next = NULL;

    if(list->head == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }

    list->tail = new_node;
    list->size++;

    return true;
}

bool remove_last(LinkedList *list) {

    if(list == NULL || list->head == NULL) return false;;

    if(list->head == list->tail) {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return true;
    }

    Node *current = list->head;
    while(current->next != list->tail) {
        current = current->next;
    }

    free(list->tail->data);
    free(list->tail);

    current->next = NULL;
    list->tail = current;
    list->size--;

    return true;
}

// int add_at(Node **head, int value, int index) {

//     if(index < 0) {
//         return 7;
//     }

//     Node *new_node = NULL;
//     if (allocate_memory(&new_node) != 0) {
//         return 1;
//     }
//     new_node->value = value;
//     new_node->next = NULL;

//     if (index == 0) {
//         new_node->next = *head;
//         *head = new_node;
//         return 0;
//     }

//     if(*head == NULL) {
//         free(new_node);
//         return 3;
//     }
    
//     Node *current = *head;
//     int local_index = 0;
//     while(current != NULL && local_index != index - 1) {
//         current = current->next;
//         ++local_index;
//     }

//     Node *temp = current->next;
//     current->next = new_node;
//     new_node->next = temp;

//     return 0;
// }

// int remove_at(Node **head, int index) {

//     if(index < 0) {
//         printf("indice invalido coloque um indice valido");
//         return 2;
//     }

//     if(*head == NULL) {
//         return 3;
//     }

//     if(index == 0) {
//       Node *temp = *head;
//       *head = temp->next;
//       free(temp);
//       return 0;
//     }

//     Node *current = *head;
//     int local_index = 0;

//     while(local_index != index - 1) {
//         current = current->next;
//         ++local_index;
//     }

//     Node *delete_node = current->next;
//     current->next = delete_node->next;
//     free(delete_node);

//     return 0;
// }

// int is_empty(Node *head) {

//     if(head == NULL) {
//         return 5;
//     }
//     return 6;
// }

// int size(Node *head, int *size_var) {

//     if(head == NULL) {
//         *size_var = 0;
//     }

//     Node *current = head;
//      while(current != NULL) {
//         ++(*size_var);
//         current = current->next;
//      }
//     return 0;
// }

// int print_list(Node *head) {

//     if(head == NULL) {
//         printf("nao tem head");
//         return 3;
//     }

//     Node *current = head;
//     while(current != NULL) {
//         if(current->next != NULL) {
//             printf("[ %d ] -> ", current->value);
//         } else {
//             printf("[ %d ] ", current->value);
//         }
//         current = current->next;
//     }
//     return 0;
// }


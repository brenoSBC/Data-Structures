#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "linked_list.h"

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

struct LinkedList
{
    Node *head;
    Node *tail;
    size_t size;
    size_t element_size;
};

LinkedList *ll_create(size_t element_size)
{

    if (element_size == 0)
        return NULL;

    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->element_size = element_size;

    return list;
}

void ll_destroy(LinkedList *list)
{

    if (list == NULL)
        return;

    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}

bool ll_add_last(LinkedList *list, const void *element)
{

    if (list == NULL || element == NULL)
        return false;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = malloc(list->element_size);
    if (new_node->data == NULL)
    {
        free(new_node);
        return false;
    }

    memcpy(new_node->data, element, list->element_size);
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        list->tail->next = new_node;
    }

    list->tail = new_node;
    list->size++;

    return true;
}

bool ll_add_at(LinkedList *list, const void *element, const int index)
{

    if (list == NULL || element == NULL || index < 0 || index > list->size)
        return false;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = malloc(list->element_size);
    if (new_node->data == NULL)
    {
        free(new_node);
        return false;
    }

    memcpy(new_node->data, element, list->element_size);

    if (index == 0)
    {
        new_node->next = list->head;
        list->head = new_node;
        if (list->tail == NULL)
        {
            list->tail = new_node;
        }
        list->size++;
        return true;
    }
    else if (index == list->size)
    {
        new_node->next = NULL;
        list->tail->next = new_node;
        list->tail = new_node;
        list->size++;
        return true;
    }

    Node *current = list->head;
    int local_index = 0;
    while (current != NULL && local_index != index - 1)
    {
        current = current->next;
        ++local_index;
    }

    Node *temp = current->next;
    current->next = new_node;
    new_node->next = temp;

    list->size++;

    return true;
}

bool ll_remove_last(LinkedList *list)
{

    if (list == NULL || list->head == NULL)
        return false;
    ;

    if (list->head == list->tail)
    {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return true;
    }

    Node *current = list->head;
    while (current->next != list->tail)
    {
        current = current->next;
    }

    free(list->tail->data);
    free(list->tail);

    current->next = NULL;
    list->tail = current;
    list->size--;

    return true;
}

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




int print_list(Node *head) {

}

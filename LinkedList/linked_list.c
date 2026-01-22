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
        return 2;
    }

    Node *new_node = NULL;

    if(allocate_memory(&new_node) != 0) {
         return 1;
    }

    new_node->value = value;
    new_node->next = NULL;
    *head = new_node;

    return 0;
}

int add_last(Node **head, int value) {

    if(*head == NULL) {
        return 3;
    }

    Node *new_node = NULL;
    if(allocate_memory(&new_node) != 0) {
        printf("\nError allocating memory\n");
        return 1;
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

    if(index < 0) {
        return 7;
    }

    Node *new_node = NULL;
    if (allocate_memory(&new_node) != 0) {
        return 1;
    }
    new_node->value = value;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }

    if(*head == NULL) {
        free(new_node);
        return 3;
    }
    
    Node *current = *head;
    int local_index = 0;
    while(current != NULL && local_index != index - 1) {
        current = current->next;
        ++local_index;
    }

    Node *temp = current->next;
    current->next = new_node;
    new_node->next = temp;

    return 0;
}

int remove_last(Node **head) {

    if(*head == NULL) {
        return 3;
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

int remove_at(Node **head, int index) {

    if(index < 0) {
        printf("indice invalido coloque um indice valido");
        return 2;
    }

    if(*head == NULL) {
        return 3;
    }

    if(index == 0) {
      Node *temp = *head;
      *head = temp->next;
      free(temp);
      return 0;
    }

    Node *current = *head;
    int local_index = 0;

    while(local_index != index - 1) {
        current = current->next;
        ++local_index;
    }

    Node *delete_node = current->next;
    current->next = delete_node->next;
    free(delete_node);

    return 0;
}

int destroy_list(Node **head) {

    if(*head == NULL) {
        return 4;
    }

    while(*head != NULL) {
        Node *temp = *head;
        *head = temp->next;
        free(temp);
    }
    return 0;
}

int is_empty(Node *head) {

    if(head == NULL) {
        return 5;
    }
    return 6;
}

int size(Node *head, int *size_var) {

    if(head == NULL) {
        *size_var = 0;
    }

    Node *current = head;
     while(current != NULL) {
        ++(*size_var);
        current = current->next;
     }
    return 0;
}

int print_list(Node *head) {

    if(head == NULL) {
        printf("nao tem head");
        return 3;
    }

    Node *current = head;
    while(current != NULL) {
        if(current->next != NULL) {
            printf("[ %d ] -> ", current->value);
        } else {
            printf("[ %d ] ", current->value);
        }
        current = current->next;
    }
    return 0;
}

void print_menu() {

    printf("\n*****************************\n");
    printf("\n         LINKED LIST         \n");
    printf("\n*****************************\n");
    printf("1 - Create head\n");
    printf("2 - Add last\n");
    printf("3 - Add at index\n");
    printf("4 - Remove last\n");
    printf("5 - Remove at index\n");
    printf("6 - Print list\n");
    printf("7 - Size\n");
    printf("8 - Is empty\n");
    printf("9 - Destroy list\n");
    printf("\n10 -  -- Exit\n");
    printf("Choose: ");
}

void take_return(int flag) {

    if(flag == 0) {
        printf("\nOperation completed successfully.\n");
    } else if(flag == 1) {
        printf("\nError: Memory could not be allocated.\n");
    } else if(flag == 2) {
        printf("\nHead already exists. Use add functions instead.\n");
    } else if(flag == 3) {
        printf("\nHead is NULL. Call create() before this operation.\n");
    } else if(flag == 4) {
        printf("\nThe list is already empty.\n");
    } else if(flag == 5) {
        printf("\nTrue.\n");
    } else if(flag == 6) {
        printf("\nFalse.\n");
    } else if(flag == 7) {
        printf("\nInvalid Index.\n");
    } else if(flag == 8) {
        printf("\n.\n");
    }
}
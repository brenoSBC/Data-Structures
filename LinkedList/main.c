#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

int main() {

    int flag;
    Node *head = NULL;
     
    flag = create(&head, 10);
    flag = add_last(&head, 20);
    flag = add_last(&head, 30);
    flag = add_last(&head, 40);
    flag = add_at(&head, 540, 2);
    // remove_last(&head);
    
    Node *current = head;

    while(current != NULL) {

        printf("%d ", current->value);
        current = current->next;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

int main() {

    Node *head = NULL;
    int flag = 0, opt = 0, value = 0, index = 0, size_var = 0;

    while(true) {
      
        print_menu();
        scanf("%d", &opt);
        if(opt == 10) break;

        switch (opt)
        {
            case 1:
                printf("\nValue: ");
                scanf("%d", &value);
                flag = create(&head, value);
                take_return(flag);
                break;

             case 2:
                printf("\nValue: ");
                scanf("%d", &value);
                flag = add_last(&head, value);
                take_return(flag);
                break;

            case 3:
                printf("\nValue: ");
                scanf("%d", &value);
                printf("\nIndex: ");
                scanf("%d", &index);
                flag = add_at(&head, value, index);
                take_return(flag);
                break;

            case 4:
                flag = remove_last(&head);
                take_return(flag);
                break;

            case 5:
                printf("\nIndex: ");
                scanf("%d", &index);
                flag = remove_at(&head, index);
                take_return(flag);
                break;

            case 6:
                flag = print_list(head);
                take_return(flag);
                break;

            case 7:
                flag = size(head, &size_var);
                take_return(flag);
                break;

            case 8:
                flag = is_empty(head);
                take_return(flag);
                break;

            case 9:
                flag = destroy_list(&head);
                take_return(flag);
                break;
            
             default:
                printf("\nInvalid option\n");
        }
    }
     
    return 0;
}
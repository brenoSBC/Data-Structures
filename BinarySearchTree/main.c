#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"

int main() 
{
    Node *root = NULL;
    add_node(&root, 10);
    add_node(&root, 9);
    add_node(&root, 8);
    add_node(&root, 11);
    add_node(&root, 20);
    add_node(&root, 45);
    add_node(&root, 21);
    add_node(&root, 12);
    add_node(&root, 1);
    add_node(&root, 2);
    add_node(&root, 6);
    print_tree(&root);

    return 0;
}
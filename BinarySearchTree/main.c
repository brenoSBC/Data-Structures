#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;

} Node;

int add_node(Node **root, int value) {

    if(*root == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = value;
        new_node->right = NULL;
        new_node->left = NULL;
        *root = new_node;
        return 0;
    }

    if(value == (*root)->value) {
        return 1;
    }

    if(value < (*root)->value) {
        return add_node(&(*root)->left, value);
    } else {
        return add_node(&(*root)->right, value);
    }
}

int main() 
{

    Node *root = NULL;
    add_node(&root, 10);
    add_node(&root, 20);
    add_node(&root, 30);



    return 0;
}
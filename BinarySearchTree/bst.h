#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;

} Node;

int add_node(Node **root, int value);

void print_tree(Node *root);

bool find(Node *root, int value);


typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;

} Node;

int add_node(Node **root, int value);

int print_tree(Node **root);


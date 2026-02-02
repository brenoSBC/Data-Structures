#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

void print_int(const void *data);
void print_float(const void *data);

int main()
{

    int x = 10, y = 20, z = 30, w = 40;
    size_t size = 0;

    LinkedList *list = ll_create(sizeof(int));
    ll_add_last(list, &x);
    ll_print(list, print_int);
    ll_add_last(list, &y);
    ll_print(list, print_int);
    ll_add_last(list, &z);
    ll_print(list, print_int);
    ll_add_last(list, &w);
    ll_print(list, print_int);
    ll_remove_last(list);
    ll_print(list, print_int);
    ll_add_at(list, &w, 1);
    ll_print(list, print_int);
    ll_remove_at(list, 1);
    ll_print(list, print_int);
    size = ll_size(list);
    printf("Size: %zu\n", size);
    ll_destroy(list);

    return 0;
}

void print_int(const void *data)
{
    printf("%d", *(const int *)data);
}

void print_float(const void *data)
{
    printf("%f", *(const float *)data);
}
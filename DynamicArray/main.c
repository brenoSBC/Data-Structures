#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int *data;      //ponteiros para os elementos
    int size;      //quantos elementos existem
    int capacity; //tamanho alocado
} DynamicArray;

void initialize(DynamicArray *arr) {

    arr->size = 0;
    arr->capacity = 4;
    arr->data = malloc(arr->capacity * sizeof(int)); // aqui sim, no heap

     if (arr->data == NULL) {
        printf("Erro alocar\n");
        exit(1);
    }
}

void destroy(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void resize(DynamicArray *arr) {
    
    int new_capacity = arr->capacity * 2; //dobra o tamanho (comportamento padrao de array dinamico)

    int *temp = realloc(arr->data, new_capacity * sizeof(int));
    if(temp == NULL) {
        printf("Eroo");
        exit(1);
    }
    arr->data = temp;
    arr->capacity = new_capacity;
}

void push_back(DynamicArray *arr) {

}

int main(void) {

    DynamicArray arr; //estrutura na stack (nao precisa ficar no heap)
    initialize(&arr);

    return 0;
}
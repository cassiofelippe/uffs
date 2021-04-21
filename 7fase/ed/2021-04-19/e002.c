#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct item {
    char value;
    struct item* prev;
};

typedef struct item Item;

typedef struct {
    Item* top;
} Stack;


void print_inverted(Item* letter) {
    if (letter == NULL) {
        return;
    }

    print_inverted(letter->prev);

    printf("%c", letter->value);
}

void split_print_free(char* word) {
    /* split */

    int i;

    Stack* stack = malloc(sizeof(Stack));

    stack->top = NULL;

    for (i = 0; i < strlen(word); i++) {
        Item* aux = malloc(sizeof(Item));
        aux->prev = NULL;
        aux->value = word[i];

        if (stack->top == NULL) {
            stack->top = aux;
        } else {
            Item* top = stack->top;
            aux->prev = top;
            stack->top = aux;
        }
    }

    /* print */

    print_inverted(stack->top);
    printf("\n");

    Item* aux = stack->top;

    while (aux != NULL) {
        stack->top = aux->prev;
        
        printf("freeing %c\n", aux->value);
        free(aux);

        aux = stack->top;
    }
}


int main() {
    split_print_free("banana");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct item {
    char value;
    struct item* prev;
    struct item* next;
};

typedef struct item Item;

typedef struct {
    Item* first;
    Item* last;
} Queue;


void split_print_free(char* word) {
    /* split */

    int i;

    Queue* queue = malloc(sizeof(Queue));

    queue->first = NULL;
    queue->last = NULL;

    for (i = 0; i < strlen(word); i++) {
        Item* aux = malloc(sizeof(Item));
        aux->next = NULL;
        aux->value = word[i];

        if (i == 0) {
            queue->first = aux;
        } else {
            Item* aux2 = queue->first;

            if (i == strlen(word) - 1) {
                queue->last = aux;
            }
            
            while (aux2->next != NULL) {
                aux2 = aux2->next;
            }

            aux2->next = aux;
        }
    }

    /* print */

    Item* aux = queue->first;

    while (aux != NULL) {
        printf("%c", aux->value);
        aux = aux->next;
    }

    printf("\n");

    /* free */

    aux = queue->first;

    while (aux != NULL) {
        Item* next = aux->next;
        printf("freeing %c\n", aux->value);
        free(aux);

        if (next != NULL) {
            next->prev = NULL;
        }
        aux = next;
    }

}


int main() {
    split_print_free("banana");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1000
#define LINE_LIMIT 10
#define EVER 1
#define true 1
#define false 0


/* STRUCTS */

struct integer {
    int value;
    struct integer *prev;
    struct integer *next;
};

typedef struct integer Integer;

typedef struct {
    Integer *first;
    Integer *last;
} List;

void print_all(List *list) {
    Integer *aux = list->first;

    printf("\n");
    for (; aux != NULL; aux = aux->next) {
        printf("%d . ", aux->value);
    }
    printf("\n");
}


Integer* insert(List *list, int value) {
    Integer *number = malloc(sizeof(Integer));

    number->value = value;
    
    if (list->first == NULL) {
        number->prev = NULL;
        number->next = NULL;
        list->first = number;
        list->last = number;
    } else {
        Integer *last = list->first;

        while (last != NULL && last->next != NULL) {
            last = last->next;
        }

        last->next = number;
        number->prev = last;
        list->last = number;
    }

    return number;
}

int contains(List *list, int value) {
    Integer *aux = list->first;

    for (;EVER; aux = aux->next) {
        if (aux == NULL) {
            break;
        }

        if (aux->value == value) {
            return true;
        }
    }

    return false;
}

void remove_middle(List *list, int value) {
    if (!contains(list, value)) {
        return;
    }

    Integer *aux = list->first;

    for (;EVER;) {
        if (aux->value == value) {
            aux->prev->next = aux->next;
            free(aux);
            break;
        }

        aux = aux->next;
    }
}

int main() {
    List *result = malloc(sizeof(List));
    Integer *element = malloc(sizeof(Integer));

    insert(result, 1);
    insert(result, 2);
    insert(result, 3);

    print_all(result);
    
    remove_middle(result, 2);

    print_all(result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>


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


Integer* add_number(List *list, int value);
void print_all(List *list);
void print_all_inverted(List *list);


int main() {
    List *numbers = malloc(sizeof(List));
    int i;

    for (i = 0; i <= 5; i++) {
        add_number(numbers, i);
    }

    print_all(numbers);
    print_all_inverted(numbers);
    
    return 0;
}


Integer* add_number(List *list, int value) {
    Integer *number = malloc(sizeof(Integer));

    number->value = value;
    
    if (list->first == NULL) {
        number->prev = NULL;
        number->next = NULL;
        list->first = number;
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

void print_all(List *list) {
    Integer *aux = list->first;

    printf("\n");
    for (; aux != NULL; aux = aux->next) {
        printf("%d . ", aux->value);
    }
    printf("\n");
}

void print_all_inverted(List *list) {
    Integer *aux = list->last;

    printf("\n");
    for (; aux != NULL; aux = aux->prev) {
        printf("%d . ", aux->value);
    }
    printf("\n");
}

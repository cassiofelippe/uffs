#include <stdio.h>
#include <stdlib.h>


struct integer {
    int value;
    struct integer *next;
};

typedef struct integer Integer;

typedef struct {
    Integer *first;
} List;


Integer* add_number(List *list, int value);


int main() {
    List *numbers = malloc(sizeof(List));
    int i;

    for (i = 0; i <= 5; i++) {
        add_number(numbers, i);
    }
    
    Integer *aux = numbers->first;
    
    printf("\n");
    for (; aux != NULL; aux = aux->next) {
        printf("%d . ", aux->value);
    }

    return 0;
}


Integer* add_number(List *list, int value) {
    Integer *number = malloc(sizeof(Integer));

    number->value = value;
    
    if (list->first == NULL) {
        number->next = NULL;
        list->first = number;
    } else {
        Integer *last = list->first;

        while (last != NULL && last->next != NULL) {
            last = last->next;
        }

        last->next = number;
    }

    return number;
}
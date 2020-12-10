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


Integer* insert_at_end(List *list, int value);
Integer* insert_at_beginning(List *list, int value);
void remove_first(List *list);
void remove_last(List *list);
void print_all(List *list);
void print_all_inverted(List *list);


int main() {
    List *numbers = malloc(sizeof(List));
    int i;

    for (i = 0; i <= 5; i++) {
        insert_at_end(numbers, i);
        if (i != 0) {
            insert_at_beginning(numbers, i*(-1));
        }
    }

    print_all(numbers);
    print_all_inverted(numbers);

    remove_last(numbers);
    remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    // remove_first(numbers);
    
    // insert_at_beginning(numbers, 69);
    // insert_at_end(numbers, 69);

    print_all(numbers);
    print_all_inverted(numbers);
    
    return 0;
}


Integer* insert_at_end(List *list, int value) {
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


Integer* insert_at_beginning(List *list, int value) {
    Integer *number = malloc(sizeof(Integer));

    number->value = value;
    
    if (list->first == NULL) {
        number->prev = NULL;
        number->next = NULL;
        list->first = number;
        list->last = number;
    } else {
        Integer *first = list->first;

        number->next = first;
        first->prev = number;
        list->first = number;
    }

    return number;
}

void remove_first(List *list) {
    Integer *aux = list->first;
    if (list->first != NULL && list->first->next != NULL) {
        aux->next->prev = NULL;
        list->first = aux->next;
        free(aux);

        // if the list contains only one element
        if (list->first->next == NULL) {
            list->last = list->first;
        }
    } else if (list->first != NULL) {
        free(aux);
        list->last = NULL;
        list->first = NULL;
    }
}


void remove_last(List *list) {
    Integer *aux = list->last;
    if (list->last != NULL && list->last->prev != NULL) {
        aux->prev->next = NULL;
        list->last = aux->prev;
        free(aux);

        // if the list contains only one element
        if (list->last->prev == NULL) {
            list->first = list->last;
        }
    } else if (list->last != NULL) {
        free(aux);
        list->last = NULL;
        list->first = NULL;
    }
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

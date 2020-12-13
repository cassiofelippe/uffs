#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1000
#define LINE_LIMIT 10
#define EVER 1


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

typedef int boolean;

typedef struct {
    boolean inserted_at_beginning;
    boolean inserted_at_middle;
    boolean inserted_at_end;
    boolean removed_from_beginning;
    boolean removed_from_middle;
    boolean removed_from_end;
} OperationData;


/* METHOD DECLARATIONS */

List* read_entry();
Integer* insert_at_end(List *list, int value);
Integer* insert_at_beginning(List *list, int value);
void remove_first(List *list);
void remove_last(List *list);
void print_all(List *list);
void print_all_inverted(List *list);
int size_of(List *list);
int index_of(List *list, int value);


int main() {
    List *result = malloc(sizeof(List));
    int i;

    result = read_entry();

    printf("\n");

    return 0;
}


/* METHODS */

List* read_entry() {
    int i = 0, n, value, index;
    char line[LINE_LIMIT], operation;
    List* result = malloc(sizeof(List));

    scanf("%d\n", &n);

    do {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != 'I' && line[0] != 'R') {
            value = atoi(&line[0]);
        } else {
            operation = line[0];
            value = atoi(&line[2]);
            
            if (operation == 'I') {
                insert_at_end(result, value);
            } else if (operation == 'R') {
                index = index_of(result, value);
            }
        }
    } while (value != 0 || i == n);

    return result;
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

int size_of(List *list) {
    Integer *aux = list->first;
    int i = 0;

    for (;EVER; i++) {
        if (aux == NULL) {
            break;
        }

        aux = aux->next;
    }

    return i;
}

int index_of(List *list, int value) {
    Integer *aux = list->first;
    int i = 0;

    for (;EVER; i++) {
        if (aux->value == value) {
            break;
        }

        aux = aux->next;
    }

    return i;
}

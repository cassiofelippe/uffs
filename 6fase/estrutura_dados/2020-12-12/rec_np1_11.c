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

void execute();
Integer* insert_at_end(List *list, int value);
Integer* insert_at_beginning(List *list, int value);
void remove_first(List *list);
void remove_last(List *list);
void remove_middle(List *list, int value);
void print_all(List *list);
void print_all_inverted(List *list);
int size_of(List *list);
int index_of(List *list, int value);
int contains(List *list, int value);


int main() {
    int n;

    scanf("%d\n", &n);
    
    do {
        execute(n);
        scanf("%d\n", &n);
    } while (n != 0);

    return 0;
}


/* METHODS */

void execute(int n) {
    int i = 0, value = 0, index;
    char line[LINE_LIMIT], operation;
    List *result = malloc(sizeof(List));
    OperationData *operations = (OperationData*) calloc(6, sizeof(boolean));

    do {
        int removed = 0;
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != 'I' && line[0] != 'R') {
            value = atoi(&line[0]);
            if (value == 0) {
                break;
            }
        } else {
            operation = line[0];
            value = atoi(&line[2]);
            
            if (operation == 'I') {
                insert_at_end(result, value);
            } else if (operation == 'R') {
                index = index_of(result, value);

                if (index == 0) {
                    operations->removed_from_beginning += true;
                    if (contains(result, value)) {
                        remove_first(result);
                    }
                    removed++;
                }

                if (index == size_of(result) - 1 || result == NULL) {
                    operations->removed_from_end += true;
                    if (contains(result, value)) {
                        remove_last(result);
                    }
                    removed++;
                }

                if (removed == 0) {
                    operations->removed_from_middle += true;
                    if (contains(result, value)) {
                        remove_middle(result, value);
                    }
                }
            }
        }

        i++;
    } while (i < n);

    // printf("\nrfb %d\nrfm: %d\nrfe: %d\n\n",
    //     operations->removed_from_beginning,
    //     operations->removed_from_middle,
    //     operations->removed_from_end
    // );

    if (operations->removed_from_beginning && operations->removed_from_end <= 1) {
        printf("fila!\n");
    } else if (operations->removed_from_end && operations->removed_from_beginning <= 1) {
        printf("pilha!\n");
    } else if (operations->removed_from_middle) {
        printf("jokerBag!\n");
    } else {
        printf("nem Turing sabe!\n");
    }
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

void remove_middle(List *list, int value) {
    if (!contains(list, value)) {
        return;
    }

    Integer *aux = list->first;

    for (;EVER;) {
        if (aux->value == value) {
            aux->prev->next = aux->next;
            free(aux);
            return;
        }

        aux = aux->next;
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

    if (!contains(list, value)) {
        return 0;
    }

    for (;EVER; i++) {
        if (aux->value == value) {
            break;
        }

        aux = aux->next;
    }

    return i;
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

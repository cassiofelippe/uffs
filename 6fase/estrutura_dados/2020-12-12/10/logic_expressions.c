#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LIMIT 500
#define EVER 1
#define true 1
#define false 0


/* STRUCTS */

struct boolean_type {
    char value;
    struct boolean_type *prev;
    struct boolean_type *next;
};

typedef struct boolean_type Boolean;

typedef struct {
    Boolean *first;
    Boolean *last;
    int elements;
} List;

typedef int boolean;


/* METHOD DECLARATIONS */

boolean E(int v1, int v2);
boolean O(int v1, int v2);
boolean X(int v1, int v2);
boolean N(int v);
boolean mount_stage(List *values, List *elements);

Boolean* insert(List *list, char value);
void print_all(List *values, List *elements);
int size_of(List *list);
int index_of(List *list, int value);
int contains(List *list, int value);


int main() {
    int n, i, initial_i;
    List *values = malloc(sizeof(List));
    List *operators = malloc(sizeof(List));
    char line[LIMIT], input;
    boolean result;

    values->elements = 0;
    operators->elements = 0;

    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';

    n = (int) atoi(strtok(line, " "));

    if (n < 10) {
        i = 2;
    } else if (n < 100) {
        i = 3;
    } else {
        i = 4;
    }

    initial_i = i;

    for (; i <= n*2 + (initial_i - 1); i += 2) {
        input = line[i];

        switch (input) {
            case 'v': {
                insert(values, 'v');
                values->elements++;
                break;
            }
            case 'f': {
                insert(values, 'f');
                values->elements++;
                break;
            }
            case 'E': {
                insert(operators, 'E');
                operators->elements++;
                break;
            }
            case 'O': {
                insert(operators, 'O');
                operators->elements++;
                break;
            }
            case 'X': {
                insert(operators, 'X');
                operators->elements++;
                break;
            }
            case 'N': {
                insert(operators, 'N');
                operators->elements++;
                break;
            }
            default: {}
        }
        // print_all(values, operators);
    }

    result = mount_stage(values, operators);

    printf("Valores: %d\n", values->elements);
    printf("Operadores: %d\n", operators->elements);
    printf("Resultado: %c\n", result ? 'v' : 'f');

    return 0;
}


/* METHODS */

boolean E(int v1, int v2) {
    return v1 && v2;
}

boolean O(int v1, int v2) {
    return v1 || v2;
}

boolean X(int v1, int v2) {
    return v1 != v2;
}

boolean N(int v) {
    return !v;
}

boolean mount_stage(List *values, List *operators) {
    Boolean *op_aux = operators->first;
    Boolean *val_aux = values->first;
    boolean v1, v2;

    v1 = val_aux->value == 'v' ? true : false;
    
    while (op_aux != NULL) {
        v2 = val_aux->next->value == 'v' ? true : false;
        switch (op_aux->value) {
            case 'E': {
                v1 = E(v1, v2);
                break;
            }
            case 'O': {
                v1 = O(v1, v2);
                break;
            }
            case 'X': {
                v1 = X(v1, v2);
                break;
            }
            case 'N': {
                v1 = N(v1);
                break;
            }
            default: {}
        }

        if (op_aux->value != 'N') {
            val_aux = val_aux->next;
        }

        op_aux = op_aux->next;
    }

    return v1;
}

Boolean* insert(List *list, char value) {
    Boolean *condition = malloc(sizeof(Boolean));

    condition->value = value;
    
    if (list->first == NULL) {
        condition->prev = NULL;
        condition->next = NULL;
        list->first = condition;
        list->last = condition;
    } else {
        Boolean *last = list->first;

        while (last != NULL && last->next != NULL) {
            last = last->next;
        }

        last->next = condition;
        condition->prev = last;
        list->last = condition;
    }

    return condition;
}

void print_all(List *values, List *operators) {
    Boolean *val_aux = values->first;
    Boolean *op_aux = operators->first;

    printf("\n");
    for (; val_aux != NULL; val_aux = val_aux->next) {
        printf("%c . ", val_aux->value);
    }

    printf("\n");
    for (; op_aux != NULL; op_aux = op_aux->next) {
        printf("%c . ", op_aux->value);
    }
    printf("values: %d, operators: %d", values->elements, operators->elements);

    printf("\n");
}

int size_of(List *list) {
    if (list == NULL) {
        return 0;
    }

    Boolean *aux = list->first;
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
    Boolean *aux = list->first;
    int i = 0, index = -1;

    if (!contains(list, value)) {
        return -1;
    }

    for (;aux != NULL; i++) {
        if (aux->value == value) {
            index = i;
        }

        aux = aux->next;
    }

    return index;
}

int contains(List *list, int value) {
    Boolean *aux = list->first;

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

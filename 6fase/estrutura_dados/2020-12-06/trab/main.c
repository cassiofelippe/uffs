#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVER 1
#define N 4


/* TYPES */

struct integer {
    int value;
    struct integer *prev;
    struct integer *next;
};

typedef struct integer Integer;


/* DEF METHODS */

void print_all(Integer *queue);
Integer* initialize();
Integer* get_first(Integer *queue);
Integer* get_last(Integer *queue);
Integer* insert_beginning(Integer *queue, int value);
Integer* insert_end(Integer *queue, int value);
Integer* remove_beginning(Integer *queue);
Integer* remove_end(Integer *queue);
void remove_all(Integer *queue);
int count(Integer *queue);


/* MAIN */

int main() {
    int n, O, I;
    char input[10];
    Integer *queue;

    scanf("%d\n", &n);

    if (n < 2) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        // scanf("%d", &O);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        O = atoi(&input[0]);

        /* first operation, queue must be 1 */
        if (i == 1 && O != 1) {
            return 1;
        }

        /* only the first operation must be 1 */
        if (O == 1 && i != 1) {
            return 1;
        }

        /* opperation must be between 1 and 6 */
        if (O < 1 || O > 6) {
            return 1;
        }

        /* if operation is 2 or 3, must insert I */
        if (O == 2 || O == 3) {
            I = atoi(&input[2]);
            // scanf("%d", &I);
        }

        printf("\nop %d | I %d", O, O == 2 || O == 3 ? I : -1); // TODO remove it
        // print_all(queue); // TODO remove it

        switch(O) {
            case 1: {
                queue = initialize();
                break;
            }

            case 2: {
                queue = insert_beginning(queue, I);
                break;
            }

            case 3: {
                queue = insert_end(queue, I);
                break;
            }

            case 4: {
                queue = remove_beginning(queue);
                printf("\n first %d, next %d", get_first(queue)->value, get_first(queue)->next->value);
                break;
            }

            case 5: {
                queue = remove_end(queue);
                break;
            }

            case 6: {
                remove_all(queue);
                break;
            }

            default: {
                if (queue == NULL) {
                    return 0;
                }

                if (i == 0) {
                    // print_all(queue); // TODO remove it
                    return 1;
                }
            }
        }
        print_all(queue); // TODO remove it
    }
    
    // print_all(queue); // TODO remove it

    return 0;
}


/* METHODS */

void print_all(Integer *queue) {
    Integer *first = get_first(queue);

    printf("\n");
    while (first != NULL) {
        printf("p %d <- | %d | -> %d n\n", first->prev != NULL ? first->prev->value : -1, first->value, first->next != NULL ? first->next->value : -1);
        first = first->next;
    }
    printf("\n");
}

Integer* initialize() {
    Integer *first = malloc(sizeof(Integer));

    first->prev = NULL;
    first->value = '\0';
    first->next = NULL;

    return first;
}

Integer* get_first(Integer *queue) {
    if (queue == 0) {
        return NULL;
    }

    if (queue->prev != NULL) {
        return get_first(queue->prev);
    } else {
        return queue;
    }
}

Integer* get_last(Integer *queue) {
    printf("\ngetting last for %d > ", queue);
    
    if (queue == 0) {
        return NULL;
    }
    
    printf("\ngetting last for %d", queue->value);

    if (queue->next != NULL) {
        return get_last(queue->next);
    } else {
        return queue;
    }
}

Integer* insert_beginning(Integer *queue, int value) {
    Integer *new_first = malloc(sizeof(Integer));
    queue = get_first(queue);

    if (queue->value == '\0') {
        queue->value = value;
        return queue;
    } else {
        new_first->next = queue;
        new_first->value = value;
        new_first->prev = NULL;
        queue->prev = new_first;
        return new_first;
    }
}

Integer* insert_end(Integer *queue, int value) {
    Integer *new_last = malloc(sizeof(Integer));
    queue = get_last(queue);
    
    if (queue->value == '\0') {
        queue->value = value;
        return queue;
    } else {
        new_last->prev = queue;
        new_last->value = value;
        new_last->next = NULL;
        queue->next = new_last;
        return new_last;
    }
}

Integer* remove_beginning(Integer *queue) {
    if (queue == NULL) {
        return NULL;
    }

    if (queue->prev == NULL && queue->next == NULL) {
        free(queue);
        return NULL;
    }

    queue = get_first(queue);

    Integer *aux = queue->next;

    aux->prev = NULL;
    
    free(queue);

    return aux;
}

Integer* remove_end(Integer *queue) {
    if (queue == NULL) {
        return NULL;
    }

    printf("\n queue %d", queue->value);
    // printf("\nq prev %d", queue != NULL && queue->prev != NULL ? queue->prev->value : -1);
    // printf("\n  next %d", queue->next);
    // printf("\nq next %d", queue != NULL && queue->next != NULL ? queue->next->value : -1);

    printf("\nlast %d", get_last(queue->value));

    if (queue->prev == NULL && queue->next == NULL) {
        free(queue);
        return NULL;
    }

    Integer *aux = malloc(sizeof(Integer));
    queue = get_last(queue);
    queue->prev->next = NULL;

    aux = queue->prev;
    free(queue);

    return aux;
}

void remove_all(Integer *queue) {
    if (queue == NULL) {
        return;
    }

    printf("\n%d", count(queue));

    if (queue->prev == NULL && queue->next == NULL) {
        free(queue);
        return;
    }

    queue = get_first(queue);
    
    while(queue->next != NULL) {
        queue = queue->next;
        free(queue->prev);
    }

    free(queue);
}

int count(Integer *queue) {
    int i;

    queue = get_first(queue);

    if (queue == NULL) {
        return 0;
    }

    for (i = 0; queue->next != NULL; i++) {
        queue = queue->next;
    }

    return ++i;
}
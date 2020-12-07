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


/* MAIN */

int main() {
    int n, O, I;
    Integer *queue;

    scanf("%d", &n);

    if (n < 2) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &O);

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
            scanf("%d", &I);
        }

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
                printf("\nbeen here");
                if (i == 0) {
                    print_all(queue); // TODO remove it
                    return 1;
                }
            }
        }
        print_all(queue); // TODO remove it
    }
    
    print_all(queue); // TODO remove it

    return 0;
}


/* METHODS */

void print_all(Integer *queue) {
    Integer *first = get_first(queue);

    printf("\n - first %d -", first->value);
    printf("\n - printing it all - \n");
    while (first != NULL) {
        printf("%d ", first->value);
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
    if (queue->prev != NULL) {
        return get_first(queue->prev);
    } else {
        return queue;
    }
}

Integer* get_last(Integer *queue) {
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
    queue = get_last(queue);
    
    if (queue->value == '\0') {
        queue->value = value;
        return queue;
    } else {
        Integer *new_last = malloc(sizeof(Integer));
        new_last->prev = queue;
        new_last->value = value;
        new_last->next = NULL;
        queue->next = new_last;
        return new_last;
    }
}

Integer* remove_beginning(Integer *queue) {
    Integer *aux = malloc(sizeof(Integer));
    queue = get_first(queue);
    queue->next->prev = NULL;

    aux = queue->next;
    free(queue);

    return aux;
}

Integer* remove_end(Integer *queue) {
    Integer *aux = malloc(sizeof(Integer));
    queue = get_last(queue);
    queue->prev->next = NULL;

    aux = queue->prev;
    free(queue);

    return aux;
}

void remove_all(Integer *queue) {
    queue = get_first(queue);
    
    while(queue->next != NULL) {
        queue = queue->next;
        free(queue->prev);
    }

    free(queue);
}
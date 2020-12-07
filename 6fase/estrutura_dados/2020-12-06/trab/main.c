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
                // TODO remove init
                break;
            }

            case 5: {
                // TODO remove end
                break;
            }

            case 6: {
                // TODO free
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
    }
    
    print_all(queue); // TODO remove it

    return 0;
}


/* METHODS */

void print_all(Integer *queue) {
    Integer *first = get_first(queue);

    printf("\n - first %d - \n", first->value);
    printf("\n - printing it all - \n");
    while (first != NULL) {
        printf("%d ", first->value);
        first = first->next;
    }
    printf("\n");
}

Integer* initialize() {
    int aux;

    Integer *first = malloc(sizeof(Integer));

    scanf("\n%d", &aux);

    first->prev = NULL;
    first->value = aux;
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
    new_first->prev = NULL;
    new_first->value = value;
    new_first->next = queue;
    queue->prev = new_first;
    
    return new_first;
}

Integer* insert_end(Integer *queue, int value) {
    Integer *new_last = malloc(sizeof(Integer));


    queue = get_last(queue);
    new_last->prev = queue;
    new_last->value = value;
    new_last->next = NULL;
    queue->next = new_last;

    return new_last;
}
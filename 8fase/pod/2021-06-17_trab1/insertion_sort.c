#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 8

void print_list(int *list) {
    int i;

    for (i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}


int insertion_sort_implementation(int *list) {
    int i, j, aux, iterations = 0, operations = 0, comparations = 0, max_sorted_index = 0;

    for (j = 1; j < LIST_SIZE; j++) {
        for (i = max_sorted_index + 1; i > 0; i--) {
            if (list[i] < list[i - 1]) {
                aux = list[i - 1];
                list[i - 1] = list[i];
                list[i] = aux;
                operations++;
                
                printf("[%dº] : [%d|%d] => ", operations, j, i);
                print_list(list);
            }

            if (i > max_sorted_index) {
                max_sorted_index = i;
            }

            comparations++;
        }

        iterations++;
    }

    return operations;
}


int main() {
    int list[LIST_SIZE], operations, i;

    for (i = 0; i < LIST_SIZE; i++) {
        scanf("%d", &list[i]);
    }

    print_list(list);

    operations = insertion_sort_implementation(list);

    printf("it took %d operations to sort\n", operations);

    return 0;
}
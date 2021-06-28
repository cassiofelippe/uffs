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


int selection_sort_implementation(int *list) {
    int i, j, aux, operations = 0, min_value_index = 0, ordered_index = 0, must_switch = 0;

    for (j = 0; j < LIST_SIZE; j++) {
        // printf("min_value_index %d, ordered_index %d\n", min_value_index, ordered_index);

        min_value_index = ordered_index;

        for (i = ordered_index; i < LIST_SIZE; i++) {
            // printf("is %d < %d ? %d\n", list[i], list[min_value_index], list[i] < list[min_value_index]);
            if (list[i] < list[min_value_index]) {
                min_value_index = i;
                must_switch = 1;
            }
        }

        // printf("analysing %d and %d, must_switch? %d\n", list[min_value_index], list[ordered_index], must_switch);

        if (min_value_index != ordered_index) {
            if (must_switch) {
                aux = list[ordered_index];
                list[ordered_index] = list[min_value_index];
                list[min_value_index] = aux;
                operations++;

                printf("[%dº] : [%d|%d] => ", operations, j, i);
                print_list(list);
                min_value_index--;
            }
        } else {
            min_value_index++;
        }

        must_switch = 0;
        ordered_index++;
    }

    return operations;
}


int main() {
    int list[LIST_SIZE], operations, i;

    for (i = 0; i < LIST_SIZE; i++) {
        scanf("%d", &list[i]);
    }

    print_list(list);

    operations = selection_sort_implementation(list);

    printf("it took %d operations to sort\n", operations);

    return 0;
}
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

int simple_bubble_sort_implementation(int *list) {
    int i, j, aux, iterations = 0;

    for (j = 0; j < LIST_SIZE; j++) {
        for (i = 0; i < LIST_SIZE; i++) {
            if (list[i] > list[i + 1] && i < (LIST_SIZE - 1)) {
                aux = list[i + 1];
                list[i + 1] = list[i];
                list[i] = aux;
                
                printf("[%d|%d] => ", j, i);
                print_list(list);
            }

            iterations++;
        }
    }

    return iterations;
}


int moderate_bubble_sort_implementation(int *list) {
    int i, j, aux, max_index_sorted = LIST_SIZE, iterations = 0, operations = 0, comparations = 0, flag;

    for (j = 0; j < max_index_sorted; j++) {
        flag = 0;
        for (i = 0; i < max_index_sorted; i++) {
            if (list[i] > list[i + 1] && i < (LIST_SIZE - 1)) {
                aux = list[i + 1];
                list[i + 1] = list[i];
                list[i] = aux;
                flag = 1;
                operations++;
                
                printf("[%d|%d] => ", j, i);
                print_list(list);
            }

            comparations++;
        }

        iterations++;
        
        if (flag == 0) {
            break;
        }
    }

    return operations;
}


int main() {
    int list[LIST_SIZE] = { 5, 18, 3, 4, 9, 7, 12, 15 }, operations;
    
    print_list(list);

    // operations = simple_bubble_sort_implementation(list);
    operations = moderate_bubble_sort_implementation(list);

    printf("it took %d operations to sort\n", operations);

    return 0;
}
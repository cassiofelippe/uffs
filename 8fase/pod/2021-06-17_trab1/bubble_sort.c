#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 8

void print_list(int *list) {
    int i;

    for (i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}

int bubble_sort_implementation(int *list) {
    int i, j, aux, iterations = 0, operations = 0, comparations = 0, flag;

    for (j = 0; j < LIST_SIZE; j++) {
        flag = 0;
        for (i = 0; i < LIST_SIZE; i++) {
            if (list[i] > list[i + 1] && i < (LIST_SIZE - 1)) {
                aux = list[i + 1];
                list[i + 1] = list[i];
                list[i] = aux;
                flag = 1;
                operations++;
                
                printf("[%dº] : [%d|%d] => ", operations, j, i);
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
    int list[LIST_SIZE], operations, i;

    for (i = 0; i < LIST_SIZE; i++) {
        scanf("%d", &list[i]);
    }

    print_list(list);

    operations = bubble_sort_implementation(list);

    printf("it took %d operations to sort\n", operations);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define LIMIT_10000 10000
#define LIMIT_50000 50000
#define LIMIT_100000 100000


void print_list(int *list, int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
}

void populate_lists(
    int *list10asc, int *list10desc, int *list10rdm,
    int *list50asc, int *list50desc, int *list50rdm,
    int *list100asc, int *list100desc, int *list100rdm
) {
    int i;
    time_t random_gen;
    
    srand((unsigned) time(&random_gen));

    for (i = 1; i <= LIMIT_100000; i++) {
        if (i <= LIMIT_10000) {
            list10asc[i] = i;
        }

        if (i <= LIMIT_50000) {
            list50asc[i] = i;
        }
        
        list100asc[i] = i;
    }
    
    for (i = LIMIT_100000; i > 0; i--) {
        if (i <= LIMIT_10000) {
            list10desc[i] = i;
        }

        if (i <= LIMIT_50000) {
            list50asc[i] = i;
        }
        
        list100asc[i] = i;
    }
    
    for (i = 1; i <= LIMIT_100000; i++) {
        if (i <= LIMIT_10000) {
            list10asc[i] = rand() % (LIMIT_10000);
        }

        if (i <= LIMIT_50000) {
            list50asc[i] = rand() % (LIMIT_50000);
        }
        
        list100asc[i] = rand() % (LIMIT_100000);
    }
}

void print_info(char *alg_type, int size, char *order, clock_t start, clock_t end) {
    double spent_time = ((double) end - start) / CLOCKS_PER_SEC / 1000;

    printf("[%s] size: %dk, order: %s, start: %ld, end: %ld\n", alg_type, size, order, start, end);
    printf("[%s] it took %lf seconds to sort\n\n", alg_type, spent_time);
}

long bubble_sort_implementation(int *list, int length) {
    int i, j, aux, iterations = 0, operations = 0, comparations = 0, flag;
    unsigned long start, end;

    start = clock();
    printf("start %ld\n", start);

    for (j = 0; j < length; j++) {
        flag = 0;
        for (i = 0; i < length; i++) {
            if (list[i] > list[i + 1] && i < (length - 1)) {
                aux = list[i + 1];
                list[i + 1] = list[i];
                list[i] = aux;
                flag = 1;
                operations++;
                
                // printf("[%d|%d] => ", j, i);
                // print_list(list);
            }

            comparations++;
        }

        iterations++;

        if (flag == 0) {
            break;
        }
    }

    end = clock();
    printf("end %ld\n", end);

    return (end - start) / (CLOCKS_PER_SEC / 1000);
}

int main() {
    int list10asc[LIMIT_10000], list10desc[LIMIT_10000], list10rdm[LIMIT_10000];
    int list50asc[LIMIT_50000], list50desc[LIMIT_50000], list50rdm[LIMIT_50000];
    int list100asc[LIMIT_100000], list100desc[LIMIT_100000], list100rdm[LIMIT_100000];
    long spent_time;

    populate_lists(
        list10asc, list10desc, list10rdm,
        list50asc, list50desc, list50rdm,
        list100asc, list100desc, list100rdm
    );

    spent_time = bubble_sort_implementation(list10asc, LIMIT_10000);
    printf("spent time %ld\n", spent_time);
    // print_info("BUBBLE_SORT", 10, "asc", *start, *end);

    spent_time = bubble_sort_implementation(list10desc, LIMIT_10000);
    printf("spent time %ld\n", spent_time);
    // print_info("BUBBLE_SORT", 10, "desc", *start, *end);

    spent_time = bubble_sort_implementation(list10rdm, LIMIT_10000);
    printf("spent time %ld\n", spent_time);
    // print_info("BUBBLE_SORT", 10, "random", *start, *end);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void populate_list(int *list, int limit, int order) {
    int i;
    time_t random_gen;
    
    srand((unsigned) time(&random_gen));

    switch(order) {
        case 0:
            for (i = 1; i <= limit; i++) {
                list[i] = i;
            }
            break;

        case 1:
            for (i = limit; i > 0; i--) {
                list[i] = i;
            }
            break;

        case 2:
            for (i = 1; i <= limit; i++) {
                list[i] = rand() % (limit);
            }
            break;
        default:
            printf("INVALID ENTRY FOR [ORDER]!\n");
    }
}

void print_info(char *alg_type, int size, char *order, clock_t start, clock_t end) {
    double spent_time = ((double) end - start) / CLOCKS_PER_SEC / 1000;

    printf("[%s] size: %dk, order: %s, start: %ld, end: %ld\n", alg_type, size, order, start, end);
    printf("[%s] it took %lf seconds to sort\n\n", alg_type, spent_time);
}

long bubble_sort_implementation(int *list, int length) {
    int i, j, aux, iterations = 0, operations = 0, comparations = 0, flag;
    clock_t start, end;

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

long selection_sort_implementation(int *list, int length) {
    int i, j, aux, operations = 0, min_value_index = 0, ordered_index = 0, must_switch = 0;
    clock_t start, end;

    start = clock();
    printf("start %ld\n", start);


    for (j = 0; j < length; j++) {
        // printf("min_value_index %d, ordered_index %d\n", min_value_index, ordered_index);

        min_value_index = ordered_index;

        for (i = ordered_index; i < length; i++) {
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

                min_value_index--;
            }
        } else {
            min_value_index++;
        }

        must_switch = 0;
        ordered_index++;
    }

    end = clock();
    printf("end %ld\n", end);

    return (end - start) / (CLOCKS_PER_SEC / 1000);
}

long insertion_sort_implementation(int *list, int length) {
    int i, j, aux, iterations = 0, operations = 0, comparations = 0, max_sorted_index = 0;
    clock_t start, end;

    start = clock();
    printf("start %ld\n", start);


    for (j = 1; j < length; j++) {
        for (i = max_sorted_index + 1; i > 0; i--) {
            if (list[i] < list[i - 1]) {
                aux = list[i - 1];
                list[i - 1] = list[i];
                list[i] = aux;
                operations++;
            }

            if (i > max_sorted_index) {
                max_sorted_index = i;
            }

            comparations++;
        }

        iterations++;
    }

    end = clock();
    printf("end %ld\n", end);

    return (end - start) / (CLOCKS_PER_SEC / 1000);
}

int main() {
    // const int limit;
    int type, limit, order;
    scanf("%d", &type); // 0: BUBBLE, 1: SELECTION, 2: INSERTION
    scanf("%d", &limit); // 0: 10K, 1: 50K, 2: 100K
    scanf("%d", &order); // 0: ASC, 1: DESC, 2: RANDOM
    long spent_time;

    switch(limit) {
        case 0:
            limit = 10000;
            break;
        case 1:
            limit = 50000;
            break;
        case 2:
            limit = 100000;
            break;
        default:
            printf("INVALID ENTRY FOR [LIMIT]!\n");
            return 1;
    }

    int list[limit];
    populate_list(list, limit, order);
    
    switch(type) {
        case 0:
            printf("BUBBLE SORT\n");
            spent_time = bubble_sort_implementation(list, limit);
            break;
        case 1:
            printf("SELECTION SORT\n");
            spent_time = selection_sort_implementation(list, limit);
            break;
        case 2:
            printf("INSERTION SORT\n");
            spent_time = insertion_sort_implementation(list, limit);
            break;
        default:
            printf("INVALID ENTRY FOR [TYPE]!\n");
            return 1;
    }

    printf("spent time %ld ms\n", spent_time);

    printf("first 10 elements: ");

    int i;

    for (i = 0; i < 10; i++) {
        printf("%d, ", list[i]);
    }

    printf("\nin a total of %d elements\n", limit);

    return 0;
}
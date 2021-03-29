#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ref(int *vet) {
    vet[0] = -1;
}


int main() {
    int i = 0, vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d, size %ld\n", i, sizeof(i));
    printf("size %ld\n", sizeof(vet));

    for (; i < 10; i++) {
        // printf("%d\n", &vet[i]);
    }

    ref(vet);

    printf("%d\n", vet[0]);
}
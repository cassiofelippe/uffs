/*

Matrícula: 1621101010

1. Crie um programa que lê 5 valores inteiros e, em seguida, mostre na tela os
valores lidos.
2. Faça uma função que receba um vetor e o seu tamanho como parâmetro e
imprima o maior e o menor elemento do vetor.
a. Esta função é do tipo void pois não retorna nenhum valor

clear;clear;gcc e001.c -o e -Wall && ./e < e001

*/

#include <stdio.h>
#include <stdlib.h>

void print_all(int *v, int size) {
    int i;

    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%d\n", v[i]);
    }
}

void print_smaller_and_greater(int *v, int size) {
    int i, smaller, greater;

    printf("\n");

    smaller = v[0];
    greater = v[0];

    for (i = 0; i < size; i++) {
        printf("%d\n", v[i]);

        if (smaller > v[i]) {
            smaller = v[i];
        }

        if (greater < v[i]) {
            greater = v[i];
        }
    }

    printf("smaller = %d\n", smaller);
    printf("greater = %d\n", greater);
}

int main() {
    int size;

    scanf("%d", &size);

    int *v = malloc(sizeof(int)*size), i = size;

    for (i = 0; i < size; i++) {
        scanf("%d", &v[i]);
    }

    print_all(v, size);
    print_smaller_and_greater(v, size);

    return 0;
}
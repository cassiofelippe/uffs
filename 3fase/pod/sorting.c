// TODO put this file in the correct folder (git repo)
/**
 * @file sorting.c
 * @author Cassio_Luis_Zamignan_Forte_Felippe
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo template para trabalho de Pesquisa e Ordenação.
 *
 *      Cada estudante deve implementar as funções conforme as assinaturas
 * abaixo e realizar as impressões dos vetores após a ordenação. Desta forma,
 * o(a) estudante deve implementar o trecho de código para impressão dos vetores
 * ordenados dentro da função `main` conforme o exemplo do Bubble Sort abaixo.
 *
 * Se necessário, declare e implemente funções auxiliares para realizar as
 * ordenações.
 *
 * Importante:Não altere as assinaturas dos métodos de ordenação!
 *
 * Caso o vetor não possa ser ordenado por algum método, imprima uma mensagem de
 * aviso e o vetor original.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */
#include <stdio.h>

void printv(int *v, int size, char *sortType);
void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
// void quickSort(int *A, int size);
// void heapSort(int *A, int size);
// void countingSort(int *A, int size);
// void radixSort(int *A, int size);


int main() {

    int i;
    // int vetor[] = {1, 22, -10, 38, 5, 7};
    // int vetor[] = { 7, 10, 5, 3, 8, 4, 2, 9, 6 };
    int vetor[] = { 23, 17, 8, 15, 9, 12, 19, 7 };
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", vetor[i]);

    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printv(bubbleVec, tamanhoVetor, "bubble sorted");

    // selection sort
    int selectionVec[tamanhoVetor];
    copia(vetor, selectionVec, tamanhoVetor);
    selectionSort(selectionVec, tamanhoVetor);
    printv(selectionVec, tamanhoVetor, "selection sorted");

    // insertion sort
    int insertionVec[tamanhoVetor];
    copia(vetor, insertionVec, tamanhoVetor);
    insertionSort(insertionVec, tamanhoVetor);
    printv(insertionVec, tamanhoVetor, "insertion sorted");

    // merge sort
    int mergeVec[tamanhoVetor];
    copia(vetor, mergeVec, tamanhoVetor);
    mergeSort(mergeVec, tamanhoVetor);
    printv(mergeVec, tamanhoVetor, "merge sorted");

    // quick sort

    // heap sort

    // counting sort

    // radix sort

    printf("\n");

    return 0;
}

void printv(int *v, int size, char *sortType) {
    int i;

    printf("\n>> %s: ", sortType);
    for (i = 0; i < size; i++) {
        printf("%d%s", v[i], i == (size - 1) ? "" : " | ");
    }
}

void copia(int *A, int *V, int size) {
    printf("\n______________________\n");
    printv(A, size, "original");

    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}

void bubbleSort(int *A, int size) {
    /* só porque não curto variáveis em upper case */
    int *v = A, h, i, tmp, changed;

    for (h = 0; h < size; h++) {
        changed = 0;

        for (i = 0; i < size; i++) {
            if (i == (size - 1)) {
                continue;
            }
            
            if (v[i] > v[i + 1]) {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                changed = 1;
            }
            
            /* descomentar a linha abaixo para visualizar o desenvolvimento */
            // printv(v, size, "bubble");
        }


        /* verifica se finalizou a ordenação */
        if (changed == 0) {
            break;
        }
    }
}

void selectionSort(int *A, int size) {
    int *v = A, i, tmp, first = 0, smaller, ismaller;

    for (first = 0; first < size; first++) {
        // printf("\nsmIndex[%d]: %d", first, v[first]);
        smaller = v[first];

        for (i = first; i < size; i++) {
            if (v[i] < smaller) {
                smaller = v[i];
                ismaller = i;
                // printf("\n>> smaller: %d", smaller);
            }
        }

        if (smaller < v[first]) {
            tmp = v[ismaller];
            v[ismaller] = v[first];
            v[first] = tmp;
        }

        /* descomentar a linha abaixo para visualizar o desenvolvimento */
        // printv(v, size, "selection");
    }
}

void insertionSort(int *A, int size) {
    int *v = A, i, tmp, isorted = 1;

    for (isorted = 1; isorted < size; isorted++) {

        for (i = isorted; i > 0; i--) {
            if (v[i] < v[i - 1]) {
                tmp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = tmp;
            } else {
                /* evita iterações desnecessárias */
                continue;
            }

            /* descomentar a linha abaixo para visualizar o desenvolvimento */
            // printv(v, size, "insertion");
        }
    }
}

void merge(int *v, int start, int end) {
    int div = end, tmp;

    /* pega o indice da metade se for par ou metade + 1 se for ímpar */
    int idiv = div % 2 > 0 ? div / 2 + 1 : div / 2;
    printf("\n>> div / 2: %d", idiv);
    
    if (idiv > 2) {
        merge(v, start, idiv);
    } else {
        merge(v, idiv + 1, end);
    }
    

    if (v[start] > v[end]) {
        tmp = v[start];
        v[start] = v[end];
        v[end] = tmp;

        /* descomentar a linha abaixo para visualizar o desenvolvimento */
        printv(v, end, "merge");
    }
}

void mergeSort(int *A, int size) {
    int *v = A, i, tmp, div = size;

    merge(v, 0, size);
}
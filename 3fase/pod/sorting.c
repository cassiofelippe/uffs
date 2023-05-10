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
#include <stdlib.h>

void printv(int *v, int size, char *sortType);
void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
// void heapSort(int *A, int size);
// void countingSort(int *A, int size);
// void radixSort(int *A, int size);

void merge(int *v, int start, int end);
void intercalate(int *v, int start, int half, int end);
void quick(int *v, int start, int end);
int partition(int *v, int start, int end);

int main() {

    int i;
    // int vetor[] = {1, 22, -10, 38, 5, 7};
    // int vetor[] = { 7, 10, 5, 3, 8, 4, 2, 9, 6 };
    // int vetor[] = { 23, 17, 8, 15, 9, 12, 19, 7 };
    // int vetor[] = { 23, 17, 15, 8, 9, 12, 19, 7 };
    // int vetor[] = { 3, 5, 8, 9, 10, 2, 4, 6, 7 };
    // int vetor[] = { 5, 27, 0, 14, 12, 31 };
    int vetor[] = { 23, 34, 0, 7, 51, 28, 14, 5, 1, 12, 30 };
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
    int quickVec[tamanhoVetor];
    copia(vetor, quickVec, tamanhoVetor);
    quickSort(quickVec, tamanhoVetor);
    printv(quickVec, tamanhoVetor, "quick sorted");

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
            printv(v, size, "bubble");
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
        printv(v, size, "selection");
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

void mergeSort(int *A, int size) {
    merge(A, 0, size - 1);
}

void merge(int *v, int start, int end) {
    int half;

    if (start < end) {
        half = (start + end) / 2;
        merge(v, start, half);
        merge(v, half + 1, end);
        intercalate(v, start, half, end);
    }
}

void intercalate(int *v, int start, int half, int end) {
    int *aux = malloc(sizeof(int) * (end - start + 1));
    int i = start, j = half + 1, k = 0;

    /* descomentar a linha abaixo para visualizar o desenvolvimento */
    // printv(v, end, "merge");

    while (i <= half && j <= end) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }

        k++;
    }

    /* when there are elements remaining in the first half */
    while (i <= half) {
        aux[k] = v[i];
        k++;
        i++;
    }

    /* when there are elements remaining in the second half */
    while (j <= end) {
        aux[k] = v[j];
        k++;
        j++;
    }

    /* transferring the elemnts back to the original array */
    for (k = start; k <= end; k++) {
        v[k] = aux[k - start];
    }

    free(aux);
}

void quickSort(int *A, int size) {
    quick(A, 0, size - 1);
}

void quick(int *v, int start, int end) {
    int pivot;

    /* descomentar a linha abaixo para visualizar o desenvolvimento */
    printv(v, end, "quick");

    if (start < end) {
        pivot = partition(v, start, end);
        quick(v, start, pivot - 1);
        quick(v, pivot + 1, end);
    }
}

int partition(int *v, int start, int end) {
    int pivot = end, k = start, i, tmp;

    for (i = start; i < end; i++) {
        if (v[i] <= v[pivot]) {
            tmp = v[i];
            v[i] = v[k];
            v[k] = tmp;
            k++;
        }
    }

    if (v[k] > v[pivot]) {
        tmp = v[k];
        v[k] = v[pivot];
        v[pivot] = tmp;
    }

    return pivot;
}

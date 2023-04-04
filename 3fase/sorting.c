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

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void printv(int *v, int size);
// void selectionSort(int *A, int size);
// void insertionSort(int *A, int size);
// void mergeSort(int *A, int size);
// void quickSort(int *A, int size);
// void heapSort(int *A, int size);
// void countingSort(int *A, int size);
// void radixSort(int *A, int size);


int main(){

    int i;
    int vetor[] = {1, 22, -10, 38, 5, 7};
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", vetor[i]);

    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printf("\nBubble sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", bubbleVec[i]);
    printf("\n");

    // selection sort

    // insertion sort

    // merge sort

    // quick sort

    // heap sort

    // counting sort

    // radix sort

    return 0;
}

void printv(int *v, int size) {
    int i;

    printf("\n>> vetor: ");
    for (i = 0; i < size; i++) {
        printf("%d%s", v[i], i == (size - 1) ? ";" : ", ");
    }
}

void copia(int *A, int *V, int size) {
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
            
            printv(v, size);
        }


        /* verifica se finalizou a ordenação */
        if (changed == 0) {
            break;
        }
    }
}

#include <stdio.h>
/*#include "funcoes.h"*/

// CRIADA BIBLIOTECA PARA O CABECALHO!!!  (funcoes01.h)
int *searchMatrix(int *matriz, int *number); // *number APONTA O ENDEREÇO DE UM VALOR NA *matriz "searchMatrix"
void searchMatrix1(int *matriz, int *number, int *p); // *p APONTA O ENDERECO DO VALOR ARMAZENADO EM *number NA *matrix EM UMA MATRIZ SEM RETURN (POR REFERENCIA)

int main(){
	int matriz[2][2], n, *number, *p, i, j, aux;

	printf("\nInsira o número a ser procurado na matriz: ");
	scanf("%d", &n);

	number = &n;

	printf("\nNúmero armazenado: %d", *number);

	i = 0;
	j = 0;
	aux = 0;

	// PREENCHE E PRINTA A matriz[2][2]
	printf("\n\n");
	while(i<2){
		while(aux<2){
			matriz[i][aux] = j;
			printf("%d ", matriz[i][aux]);
			aux++;
			j++;
		}
		i++;
		aux = 0;
		printf("\n");
	}

	i = 0;
	aux = 0;

	while(i<2){
		while(aux<2){
			if(matriz[i][aux] == n){
				printf("\nNúmero %d encontrado em matriz[%d][%d]\n", n, i, aux);
				n = 9999;
				return;
			}
			aux++;
		}
		i++;
		aux = 0;
	}

	if(n != 9999){
		printf("\nNúmero não encontrado\n");
	}

	return 0;
}

// TAREFA NO MOODLE!!!!!
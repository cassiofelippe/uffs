#include <stdio.h>

void swap(int *a, int *b){
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int main(){
	int c, d;

	printf("\nInsira o valor de a: ");
	scanf("%d", &c);

	printf("\nInsira o valor de b: ");
	scanf("%d", &d);

	swap(&c, &d);

	printf("\nValor de c: %d, d: %d\n", c, d);

	return 0;
}

// ALGORITMO PARA INVERTER VALORES DE VARIÁVEIS POR REFERÊNCIA (PONTEIROS)
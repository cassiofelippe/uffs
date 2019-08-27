#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n, *p;

	printf("\nInsira a quantidade de posições do vetor: ");
	scanf("%d", &n);

	p = (int *)malloc(n*4);

	for(i = 0; i < n; i++){
		printf("\nInsira o valor: ");
		scanf("%d", p);
		p++;
	}

	p--;

	printf("\nVetor:\n");
	for(i = 0; i < n; i++){
		printf("%d, ", *p--);
	}

	printf("\n");
	return 0;
}
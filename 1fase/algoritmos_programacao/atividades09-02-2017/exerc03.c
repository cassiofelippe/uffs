#include <stdio.h>

void teste(int *a, int *b, int *c){
	*a = *a * *b * *c;
}

int main(){
	int *a, *b, *c, x, y, z;

	printf("Insira os 3 valores a serem multiplicados: ");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	teste(&x, &y, &z);

	printf("\nA multiplicacao é: %d", x);

	return 0;
}

// PONTEIROS - MULTIPLICACAO POR PONTEIROS
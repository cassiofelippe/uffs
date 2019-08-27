#include <stdio.h>

int main(){
	int valor1 = 5, valor2 = 15;

	int *p1, *p2;

	p1 = &valor1;
	p2 = &valor2;

	*p1 = 10;
	*p2 = *p1;
	p1 = p2;
	*p1 = 20;

	printf("Valor 1 é %d\n", valor1);
	printf("Valor 2 é %d\n", valor2);

	return 0;
}
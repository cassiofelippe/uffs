#include <stdio.h>
#include <stdlib.h>

void quadrado(int *a, int *b){
	int *c;

 	c = (int *)malloc(4);
 	if(c){				// CONFERE SE O ESPAÇO FOI ALOCADO
	 	*c = *a;
	 	*c *= *c;
	 	*a = *c;
 		
 		*c = *b;
 		*c *= *c;
 		*b = *c;
 	}

 	free(c);			// LIMPA O ESPAÇO NO HEAP
 	c = NULL;			// LIBERA O ESPAÇO ANTERIORMENTE OCUPADO

}

int main(){
 int a, b;
 printf("Informe dois valores: ");
 scanf("%d %d", &a, &b);
 quadrado(&a, &b);
 printf("O quadrado de a é: %d e de b é %d.\n", a, b);

 return 0;
}

// QUADRADO DE DOIS VALORES, A CONTA FEITA COM UM PONTEIRO ALOCADO DINAMICAMENTE
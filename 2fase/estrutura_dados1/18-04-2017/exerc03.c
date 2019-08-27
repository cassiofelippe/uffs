#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 1, n=5, *p, *pNew, x;

	p = (int *)malloc(n*sizeof(int)); // sizeof(int) == 4

	if(p == NULL){
		exit(0);
	}
	while(1){
		printf("\nInsira o valor: ");
		
		if(!scanf("%d", &x)){
			break;
		}

		if(i % 5 == 0){
			n+=5;
			pNew = (int *)realloc(p, sizeof(int)*n);
			if(pNew){
				printf("\nMemória realocada com sucesso!");
			}
			p = pNew;
		}
		*(p+i) = x;
		i++;
	}

	printf("\nVetor:\n");
	for(i = 0; i < n; i++){
		printf("%d, ", *(p+i));
	}

	printf("\n");
	free(p);
	return 0;
}
#include <stdlib.h>
#include <stdio.h>

int main(){
	int matriz[3][3], i, j;

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j] < 0){
				printf("\nInsira um novo valor: ");
				j--;
			}
		}
	}
	
	int salva = 0;

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(salva < matriz[i][j]){
				salva = matriz[i][j];
			}
		}
	}

	printf("\nO maior número é: %d\n", salva);

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%5d", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//	MATRIZ: Lê 9 números, identifica o maior número, depois os printa em formato matricial

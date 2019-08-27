#include <stdio.h>

int main(){
	int matriz[3][3], i, j, k, l, m, notaNove = 0, nota, notaRepetida = 0, jaPrintou[9];

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j] < 0 || matriz[i][j] > 10){
				printf("\nInsira um novo valor: ");
				j--;
			}
		}
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(matriz[i][j] == 9){
				notaNove++;
			}
		}
	}

	printf("\nA nota 9 aparece %d vezes\n", notaNove);

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			nota = matriz[i][j];
			for(k=0; k<3; k++){
				for(l=0; l<3; l++){
					if(nota == matriz[k][l]){
						notaRepetida++;
					}
				}
			}
			
			for(m=0; m<9; m++){
				if(nota == jaPrintou[m]){
					printf("\nA nota %d se repete %d vezes", nota, notaRepetida);
				}
			}

			notaRepetida = 0;
			jaPrintou[i] = nota;
		}
	}

	printf("\n");

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%5d", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
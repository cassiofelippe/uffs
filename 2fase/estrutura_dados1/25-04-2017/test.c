#include <stdio.h>

int main(){
	int i, j, n, div, aux;
	printf("Informe um valor: ");
	scanf("%d", &n);

	for(j=0; j<=n; j++){
		aux = 0;
		for(i=1; i<=n; i++){
			if(j % i == 0){
				aux++;
			}
		}
		printf("\n");
	}

	return 0;
}
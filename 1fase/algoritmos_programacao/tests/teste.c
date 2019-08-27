#include <stdio.h>
#include <string.h>

void lbff(){
	char c;
	while(c = getchar() != '\n');
}
int main(){
	int i, a, aux, filial[1000];
	char cachorro[1000][60], teste[59];
	char x = 'x';
	printf("\nx == %s", x);
	for(i = 0; i < 1000; i++){
		printf("\nInsira o nome da filial ou x: ");
		fgets(cachorro[i], 59, stdin);
		printf("\nCachorro: %s", cachorro[i]);
		if(cachorro[i] == x){
			break;
		}
		filial[i] = i;
		lbff();
	}
	printf("\ni == %d", i);
	printf("\nDigite o nome da filial: ");
	fgets(teste, 59, stdin);
	
	for(i = 0; i < 1001; i++){
		if(strcmp(teste, cachorro[i])){
			aux = 1;
			break;
		}
	}
	
	printf("\n i = %d", i);
	if(aux != 1)
		printf("Filial não cadastrado \n");
	else
		printf("Filia encontrada, filial número: %d Nome: %s\n", filial[i], cachorro[i]);

	aux = 0;

	return 0;
}
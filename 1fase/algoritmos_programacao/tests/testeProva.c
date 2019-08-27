#include <stdio.h>
#include <string.h>

int main(){
	printf("\n\nNOT WORKING!!!\n\n")
	char palavra[20], invertida[20];

	scanf("%s", palavra);
	getchar();

	int length, i, j;

	length = strlen(palavra);

	printf("\npalavra.length: %d", length);

	for(i=0, j = length; i < length; i++, j--){
		invertida[i] = palavra[j];
		invertida[j] = palavra[i];
	}

	printf("\n\nInvertida: -%s-", invertida);
	printf("\nPalavra: -%s-\n", palavra);

	if(strcmp(palavra, invertida) == 0){
		printf("\nTrue");
		printf("\nInvertida: %s\n", invertida);
	}else{
		printf("\nFalse");
	}
}
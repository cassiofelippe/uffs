#include <stdio.h>
#include <string.h>
int main(){
	char palavra[20];

	scanf("%s", palavra);

	int len, i, j;

	len = strlen(palavra);
	char aux[len];
	for(i = 0, j = len - 1; i < len; i++,j--)
		aux[i] = palavra[j];
	palavra[i] = '\0';

	if(strcmp(aux, palavra) == 0){
		printf("\nTrue");
	}else{
		printf("\nFalse");
	}
}
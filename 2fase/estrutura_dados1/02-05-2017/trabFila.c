#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Node	{
	int num;
	struct Node *prox;
};

typedef struct Node node;

void push(node *end, node *init){
	node *p = (node*) malloc(sizeof(node));

	if(init != NULL){
	}else{
		printf("\nINIT ESTÁ NULO, FILA VAZIA");
		init = p;
		end = p;
	}
}

// NÃO É NECESSÁRIO ALOCAR ESPAÇO NA FUNÇÃO POP
node *pop(){
	return 0;
}

int main(){
	node *end = NULL;
	node *init = NULL;

	int option;

	while(1){
		printf("\n0 - Desliga\n1 - Push\n2 - Pop\n\nInsira sua opção: ");
		scanf("%d", &option);
		switch(option){
			case 0:
				printf("shutdown\n");
				return 0;
			case 1:
				push(end, init);
				break;
			case 2:
				pop();
				break;
			default:
				printf("\nEntrada inválida");
				break;
		} 

		printf("\n\n");
	}

	return 0;
}

// FILA - AULA DO DIA 02-05 E 05-05-2017

/** AO USAR malloc/realloc SEMPRE CONFERIR SE A ALOCAÇÃO FOI BEM SUCEDIDA:
	*	
	*	if(ponteiroDaAlocacao != NULL){
	*		code...
	*	}else{
	*		printf("\nCould not allocate memory! System shutting down...");
	*	}
	*
	*/
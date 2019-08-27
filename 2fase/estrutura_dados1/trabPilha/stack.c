#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

//criação de uma struct tipo produto
typedef struct product{
	int cod;
	char name[TAM];
	float price;
}Product;

//criação de uma struct tipo pilha
typedef struct stack{
	Product *info;
	int top;
}Stack;

void push(){
}

char pop(){
}

int main(){
	int option;
	Stack main;

	main.top = -1;

	while(1){
		printf("\n\n");
		printf("******* Menu Principal *********\n");
		printf("* 1 - Inserir produto na pilha *\n");
		printf("* 2 - Excluir produto da pilha *\n");
		printf("* 3 - Listar produtos da pilha *\n");
		printf("* 0 - Desligar o programa      *\n");
		printf("********************************\n");
		printf("\nEntrada: ");
		scanf("%d", &option);

		switch(option){
			case 1:
				// INSERIR PRODUTO NA PILHA
			case 2:
				// EXCLUIR PRODUTO DA PILHA
			case 3:
				// LISTAR PRODUTOS DA PILHA
			case 0:
				// DESLIGAR O PROGRAMA
				printf("\nTem certeza que deseja encerrar o programa?");
				printf("\nInsira:\n1 para desligar\n0 para voltar ao menu inicial\nEntrada: ");
				scanf("%d", &option);
				if(option == 1){
					printf("\nSystem shutting down...\n");
					return 0;
				}else if(option == 0){
					printf("\nVoltando ao menu inicial...\n");
					break;
				}else{
					printf("\nEntrada inválida! Voltando ao menu inicial...\n");
					break;
				}
			default:
				printf("\nEntrada inválida!\nTente novamente...\n");
		}
	}

	return 0;
}
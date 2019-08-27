#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINE A CARTA COM NAIPE,
// NUMERO (1,2,3,4,5,6,7,10,11,12)
// CARTA ANTERIOR (back)
// PRÓXIMA CARTA (next)
typedef struct card {
	int num;
	int type;
	struct card * next;
	struct card * back;
}Card;

Card *start(){
	return NULL;
}



int main(){
	Card * card;
	int option;

	// INICIALIZA A STRUCT (COMO NULA)
	card = start();


	while(1){
		printf("\n\n");
		printf("------ MENU -------");
		printf("\n1 - Insert a card");
		printf("\n2 - Remove a card");
		printf("\n3 - Show all cards");
		printf("\n0 - System shutdown");
		printf("\n-------------------\n");
		printf("\nInsert: ");
		scanf("%d", &option);

		switch(option){
			case 1:
				printf("\n--Insert card--");
				break;
			case 2:
				printf("\n--Remove card--");
				break;
			case 3:
				printf("\n--Show all cards--");
				break;
			case 0:
				printf("\nAre you sure?\n1 to shut down or 0 to cancel\nInsert: ");
				scanf("%d", &option);
				if(option == 1){
					printf("\nSystem shutting down...\n");
					return 0;
				}else if(option == 0){
					printf("\nReturning to MENU...");
					break;
				}else{
					printf("\nInvalid entry! Returning to MENU...");
					break;
				}
				default:
					printf("\nInvalid entry! Returning to MENU...");
					break;					
		}

			// INSERIR A CARTA (ATÉ CRIAR UMA FUNÇÃO DE ALEATORIDADE PARA ENTREGAR AS CARTAS)

	}


	return 0;
}
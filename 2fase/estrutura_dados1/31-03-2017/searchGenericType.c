#include <stdio.h>

#define SIZE 10
#define INT 1
#define FLOAT 2
#define CHAR 3

void search(void *init, int size, int type){
	switch(type){
		case INT:
		// Usa o ponteiro void pra varer o vetor e buscar os dados
		break;
		case FLOAT:
		// Usa o ponteiro void pra varer o vetor e buscar os dados
		break;
		case CHAR:
		// Usa o ponteiro void pra varer o vetor e buscar os dados
		break;
		default: break;
	}
}

int main(){
	int vetInt[SIZE] = {1,2,4,5,-9,10,2,8,9,10};
	char vetChar[SIZE] = {"Jacson Tte"};
	search(vetInt, SIZE, 1);
	return 0;
}
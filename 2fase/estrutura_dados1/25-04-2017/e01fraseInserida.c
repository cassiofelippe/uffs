#include <stdio.h>
#include <string.h>

#define MAX 100 // length de stack.frase

typedef struct{
	char string[MAX];
	int top;
} Stack;

int push(Stack *s, char c){
	s -> string[++s -> top] = c;
}

char pop(Stack *s){
	return s -> string[s -> top--];
}

int main(){
	char frase[MAX];
	Stack stack;
	int i, j;
	
	printf("\nInsira a frase: ");
	fgets(frase, MAX, stdin);

	stack.top = -1;

	for(i = j = 0; i < frase[i]; i++){
		if(frase[i] == ' ' || frase[i] == '\n'){
			while(frase[j] != ' ' && frase[j] != '\n'){
				frase[j++] = pop(&stack);
			}
			j++;
		}else{
			push(&stack, frase[i]);
		}
	}

	printf("\nPalavras Invertidas: %s\n", frase);

	return 0;
}

// INVERTE CADA PALAVRA DA STRING!
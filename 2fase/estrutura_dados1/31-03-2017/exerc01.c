#include <stdio.h>

void imprime(char *v, int n){
	char *c;

	for(c = v; c < v + n; v++){
		printf("%c, ", *c);
	}
}

int main(){
	char v[5] = "abcde";
	int n = 0;
	imprime(v, n);
}


// EXERCICIO DE AULA, 
// O OBJETIVO É SE N FOR MAIOR QUE 0, 
// LOOP INFINITO, SE FOR IGUAL OU MENOR, 
// NÃO ENTRA NO LOOP
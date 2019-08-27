#include <stdio.h>

void imprime (char *v, int n){
	char *c;
	for(c = v;c<v+n;v++){
		printf("%c", *c);
	}
}

int main(){
	char *v;
	char c;
	int n = 3;

	printf("\nInsira char c: ");
	scanf("%c", &c);

	v = &c;

	imprime(v, n);

	return 0;
}
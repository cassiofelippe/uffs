#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nome[50];
char endereco[100];
int matricula;
} estudante;

int main(){
	int i, n;
	estudante *p;

	printf("\nInsira a quantidade de posições do vetor: ");
	scanf("%d", &n);

	p = (estudante *)malloc(sizeof(estudante) * n);

	for(i = 0; i < n; i++){
		printf("\nInsira o nome: ");
		scanf("%s", p[i].nome);
		getchar();

		printf("\nInsira o endereço: ");
		scanf("%s", p[i].endereco);
		getchar();

		printf("\nInsira a matrícula: ");
		scanf("%d", &p[i].matricula);
		getchar();
	}

	printf("\n");

	for(i = n-1; i >= 0; i--){
		printf("%s\n", p[i].nome);
		printf("%s\n", p[i].endereco);
		printf("%d\n", p[i].matricula);
		printf("\n");
	}

	printf("\n");
	return 0;
}
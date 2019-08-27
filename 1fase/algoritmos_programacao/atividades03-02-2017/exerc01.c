#include <stdio.h>
#include <sitlib.h>
#include <math.h>

int numPerfeito(int n){
	int i, aux, num[50], evitaLixo = 0, somaValores = 0, deuCerto;

	for(i=1; i<n; i++){
		if(n%i == 0){
			num[evitaLixo] = i;
			evitaLixo++;
		}
	}

	for(i=0; i<evitaLixo; i++){
		somaValores += num[i];
	}

	if(somaValores == n){
		printf("True")
	}

}

int main(){
	
	int n, resposta;

	printf("Insira um número: ");
	scanf("%d", &n);

	resposta = numPerfeito(n);

	if(resposta){
		printf("certo");
	}else{
		printf("errado");
	}

	return 0;
}
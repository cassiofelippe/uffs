#include <stdio.h>

void calculaQuadrado(int l, float *area, float *perimetro){

	*area = (l * l);
	*perimetro = (l * 4);
}

int main(){
	int l;
	float area, perimetro;

	printf("\nInsira o valor do lado do quadrado: ");
	scanf("%d", &l);

	calculaQuadrado(l, &area, &perimetro);

	printf("\nÁrea: %f, Perímetro: %f\n", area, perimetro);

	return 0;
}

// CALCULAR O PERÍMETRO E ÁREA POR REFERÊNCIA EM FUNÇÃO VOID
#include <stdio.h>

int main() {
  float peso, altura, ideal;
  char sexo;

  printf("Insira seu sexo (M ou F): ");
  scanf("%c", &sexo);

  printf("Insira seu peso: ");
  scanf("%f", &peso);

  printf("Insira sua altura: ");
  scanf("%f", &altura);

  ideal = (72.7 * altura) - 58;

  printf("\nPeso ideal: %f, seu peso: %f\n", ideal, peso);

  return 0;
}
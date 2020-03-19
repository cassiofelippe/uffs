/*
  Uma fábrica produz calças utilizando pedaços de tecidos inteiros.
  Cada pedaço tem 11 metros quadrados.
  Na fabricação das calças, 5 calças são fabricadas a partir de cada pedaço, porém 15% de tecido é desperdiçado.
  Faça um programa que dado a quantidade de pedaços de tecido disponíveis,
  calcule o ńumero de calças que podem ser fabricadas e o tecido desperdiçado (em metros quadrados).
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  int piece = 11, pantsPerPiece = 5, quantity, pants = 0;
  float wastePerPiece = 11 * 0.15, waste = 0.0;

  printf("Insert the quantity of pieces: ");
  scanf("%d", &quantity);

  while (quantity > 0) {
    pants += 5;
    waste += wastePerPiece;
    quantity--;
  }

  printf("The factory was able to produce %d pants with %.2fm of waste!", pants, waste);
  printf("\n");
}
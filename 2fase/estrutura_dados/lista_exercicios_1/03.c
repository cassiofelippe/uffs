/*
  Uma fábrica de camisetas gasta, para fabricar sua camiseta padrão, 100g de algodão.
  Sabendo-se que para cada camiseta é desperdiçado 5% do algodão
  que pode ser utilizado para a fabricação de outras camisetas.
  Faça um programa que calcule quantas camisetas podem ser fabricadas dada uma quantidade de algodão.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  int cotton = 100, quantity, shirts = 0, wastePerPiece = 5;

  printf("Insert the quantity of cotton in grams: ");
  scanf("%d", &quantity);

  if (quantity < 100) {
    printf("Not enough cotton!\n");
    return;
  }

  while (quantity >= 100) {
    shirts++;
    quantity -= 100;
    quantity += wastePerPiece;
  }

  printf("The factory produced %d shirt%s!", shirts, shirts > 1 ? "s" : "");
  printf("\n");
}
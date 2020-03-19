/*
  Dados o número de caracteres de um texto digitado e velocidade
  de impressão de uma impressora jato de tinta (velocidade em caracteres por segundo),
  faça um algoritmo que calcule quantos minutos serão necessários para imprimir o texto.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  int chars;
  float charsPerSecond, minutes;

  printf("\nInsert the number of chars: ");
  scanf("%d", &chars);

  printf("\nInsert the printer's speed (chars per second): ");
  scanf("%f", &charsPerSecond);

  minutes = (chars / charsPerSecond) / 60;

  printf("\nIt will take %.2f minutes to print!", minutes);
  printf("\n");
}
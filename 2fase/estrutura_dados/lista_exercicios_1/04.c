/*
  Faça um algoritmo para calcular o perímetro de um triângulo.
  O perímetro é a soma dos lados da figura.
  Para triângulo deverá ser solicitado o comprimento da base, da aresta da direita e da aresta da esquerda.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  float s1, s2, s3, perimeter;

  printf("Insert the size of each of the three sides of a triangle: ");
  scanf("%f", &s1);
  scanf("%f", &s2);
  scanf("%f", &s3);

  perimeter = s1 + s2 + s3;

  printf("The perimeter is %.2f!", perimeter);
  printf("\n");
}
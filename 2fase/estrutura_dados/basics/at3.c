#include <stdio.h>

int main() {

  // 1
  printf("\n");
  printf("Produto entre 28 e 45: %d", 28 * 45);

  // 2
  float x, y, z, media;
  
  printf("\n");
  printf("Insira 3 números\n");
  
  scanf("%f", &x);
  scanf("%f", &y);
  scanf("%f", &z);
  
  media = (x + y + z) / 3;

  printf("\nMédia: %.2f", media);


  // 3
  printf("\n");
  int l;

  printf("Insira um valor inteiro: ");
  scanf("%d", &l);

  printf("Antecessor: %d, Sucessor: %d", l - 1, l + 1);


  // 4
  printf("\n");

  float a, b;

  printf("Insira dois números: ");
  scanf("%f", &a);
  scanf("%f", &b);

  printf("\nSoma: %f", a + b);

  // 5
  printf("\n");

  float t;

  printf("Insira um número: ");
  scanf("%f", &t);

  printf("Terça parte do número é: %.2f", t / 3);


  printf("\n");

  return 0;
}
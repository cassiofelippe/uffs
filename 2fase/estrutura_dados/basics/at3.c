#include <stdio.h>

void at1() {
  printf("Produto entre 28 e 45: %d", 28 * 45);  
}

void at2() {
  float x, y, z, media;
  
  printf("\n");
  printf("Insira 3 números\n");
  
  scanf("%f", &x);
  scanf("%f", &y);
  scanf("%f", &z);
  
  media = (x + y + z) / 3;

  printf("\nMédia: %.2f", media);
}

void at3() {
  int l;

  printf("Insira um valor inteiro: ");
  scanf("%d", &l);

  printf("Antecessor: %d, Sucessor: %d", l - 1, l + 1);
}

void at4() {
  float a, b;

  printf("Insira dois números: ");
  scanf("%f", &a);
  scanf("%f", &b);

  printf("\nSoma: %f", a + b);
}

void at5() {
  float t;

  printf("Insira um número: ");
  scanf("%f", &t);

  printf("Terça parte do número é: %.2f", t / 3);
}

int main() {
  at1();
  printf("\n");

  at2();
  printf("\n");

  at3();
  printf("\n");

  at4();
  printf("\n");

  at5();
  printf("\n");

  return 0;
}
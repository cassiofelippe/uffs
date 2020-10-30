#include <stdio.h>

void subtract(int *a, int *b) {
  *a = *a - *b;
}

int main() {
  int a = 3, b = 2;

  subtract(&a, &b);

  printf("\n>> %d\n", a);

  return 0;
}

/*
Escreva uma função que recebe dois parâmetros (inteiros) a e b,
e guarda no primeiro parâmetro (a) o valor
da subtração dos dois valores (a = a-b)
*/

#include <stdio.h>

#define VET_LENGTH 10

int* double_values(int *v, int length) {
  int i = 0;
  
  for (i = 0; i < length; i++) {
    v[i] = v[i] * 2;
  }

  return v;
}

int main() {
  int v[VET_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  double_values(v, (sizeof v / sizeof *v));

  return 0;
}

/*
Escreva uma função que receba um vetor V com 10 inteiros armazenados.
A função deve retornar o vetor V com o valor de cada posição multiplicado por 2.
Os valores devem ser acessíveis fora do método.
*/

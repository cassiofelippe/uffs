#include <stdio.h>

#define VET_LENGTH 5

void greater_and_minor(int *v, int length, int *g, int *m) {
  int greater, minor;

  for (int i = 0; i < length; i++) {
    if (i > 0 && i < length - 1) {
      greater = greater > v[i] ? greater : v[i];
      minor = minor < v[i] ? minor : v[i];
    } else if (i == 0) {
      greater = v[i];
      minor = v[i];
    // } else if (i == length - 1) {
    }

    *g = greater;
    *m = minor;
  }
}


int main() {
  int v[VET_LENGTH] = {5, 2, 3, 1, 4}, g, m;

  greater_and_minor(v, (sizeof v / sizeof *v), &g, &m);

  printf(">> g: %d\n", g);
  printf(">> m: %d\n", m);

  return 0;
}




/*
Escreva um método que receba como parâmetros um vetor de inteiros,
e retorne o maior elemento e o menor elemento.
Observe que uma função em C não pode retornar dois valores,
assim você deverá passar por referência duas variáveis,
uma que represente o maior e outra o menor valor do vetor
*/
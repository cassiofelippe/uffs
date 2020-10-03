/*
 * Tarefa de laboratorio 06 - Greve
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Cassio Luis Zamignan Forte Felippe
 * Matricula: 1621101010
 *
 */

#include <stdio.h>

int main() {
  /* Dica:
   *
   * Suponha que voce declarou uma variavel do tipo int, uma variavel do tipo
   * char e outra variavel do tipo int da seguinte maneira:
   *
   * int n;
   * char a;
   * int x;
   *
   * Para ler uma linha que contem um inteiro seguida de uma linha que contem
   * um caractere e um inteiro separados por um espaco em branco, voce pode
   * usar os seguintes comandos:
   *
   * scanf("%d\n", &n);
   * scanf("%c %d\n", &a, &x);
   *
   */

  int i, n, x, total_gastos = 0, total_entradas = 0;
  char tipo;

  scanf("%d\n", &n);

  if (n < 1 || n > 100000) {
    printf("Erro! Número de valores deve ser entre 1 e 100.000!");
    return 1;
  }

  for (i = 0; i < n; i++) {
    scanf("%c %d", &tipo, &x);
    getchar();

    if (x < 1 || x > 100000) {
      printf("Erro! Valor deve ser entre 1 e 100.000!");
      return 1;
    }

    if (tipo == 'V' || tipo == 'v') {
      total_entradas += x;
    } else if (tipo == 'G' || tipo == 'g') {
      total_gastos += x;
    } else {
      printf("Erro! Tipo de gasto inválido!");
      return 1;
    }
  }

  if (total_entradas >= total_gastos) {
    printf("A greve vai parar.");
  } else {
    printf("NAO VAI TER CORTE, VAI TER LUTA!");
  }

  printf("\n");
  return 0;
}
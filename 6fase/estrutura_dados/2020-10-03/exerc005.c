/*
 * Tarefa de laboratorio 05 - Bazinga
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Cassio Luis Zamignan Forte Felippe
 * Matricula: 1621101010
 *
 */

#include <stdio.h>

#define MAX_INPUT 100

/* executa a comparação */
int compare(char b, char results[]) {
  int i;
  for (i = 0; i < 2; i++) {
    if (results[i] == b) {
      return 1;
    }
  }

  return -1;
}

/*
  devolve o resultado do jogo
  0 = empate
  1 = A ganha
 -1 = B ganha
*/
int play(char a, char b) {
  /* se A é igual a B, significa empate */
  if (a == b) {
    return 0;
  }

  /* "matriz" para determinar quem se o A ganha ou perde */
  if (a == 'e') {
    char win_results[2] = {'l', 't'};
    return compare(b, win_results);
  } else if (a == 'a') {
    char win_results[2] = {'e', 's'};
    return compare(b, win_results);
  } else if (a == 't') {
    char win_results[2] = {'a', 'l'};
    return compare(b, win_results);
  } else if (a == 'l') {
    char win_results[2] = {'s', 'a'};
    return compare(b, win_results);
  } else if (a == 's') {
    char win_results[2] = {'t', 'e'};
    return compare(b, win_results);
  }

  /*
    caso A não empate (primeira condição)
    ou não ganhe (matriz acima)
    retorna perda (B ganha)
  */
  return 99;
}

int main() {
  /* Dica:
   *
   * Suponha que voce declarou uma variavel do tipo int e duas variaveis do
   * tipo char da seguinte maneira:
   *
   * int n;
   * char a;
   * char b;
   *
   * Para ler uma linha que contem um inteiro seguida de uma linha que
   * contem dois caracteres separados por um espaco em branco, voce pode usar
   * os seguintes comandos:
   *
   * scanf("%d\n", &n);
   * scanf("%c %c\n", &a, &b);
   *
   * */

  int n, i;
  char a[MAX_INPUT], b[MAX_INPUT];
  
  scanf("%d\n", &n);
  
  if (n > 100) {
    printf("ERRO! Número não deve ser maior que 100!\n");

    return 1;
  }

  for (i = 0; i < n; i++) {
    scanf("%c %c", &a[i], &b[i]);
    getchar();
  }

  for (i = 0; i < n; i++) {
    int result = play(a[i], b[i]);

    if (result == 1) {
      printf("Caso #%d: Bazinga!", i + 1);
    } else if (result == -1) {
      printf("Caso #%d: Raj trapaceou!", i + 1);
    } else if (result == 0) {
      printf("Caso #%d: De novo!", i + 1);
    }
    
    printf("\n");
  }

  return 0;
}

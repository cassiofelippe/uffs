/*
 * Tarefa de laboratorio 07 - Armazenando e imprimindo informacoes sobre nomes
 *
 * GEX605 AB 2020/1
 *
 * Nome:      Cassio Luis Zamignan Forte Felippe
 * Matricula: 1621101010
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 42 // 40 + 2
#define MAX_ID_LENGTH 10

int main() {
  /* Dica:
   *
   * Suponha que voce declarou as seguintes variaveis (no codigo final, T deve
   * ser substituido por um valor numerico):
   *
   * int n;
   * char str[T];
   *
   * Para ler uma linha que contem um inteiro seguida de uma linha que contem
   * uma string, voce pode usar os seguintes comandos:
   *
   * scanf("%d\n", &n);
   *
   * fgets(str, sizeof(str), stdin);
   * str[strcspn(str, "\n")] = '\0';
   *
   */

  int n, i, j, student_id[MAX_STUDENTS];
  char names[MAX_STUDENTS * MAX_NAME_LENGTH],
       list_names[MAX_STUDENTS][MAX_NAME_LENGTH],
       ids_letters[MAX_STUDENTS * MAX_ID_LENGTH],
       list_letters[MAX_STUDENTS][MAX_ID_LENGTH],
       student_fol_name[MAX_STUDENTS][MAX_ID_LENGTH],
       student_id_tmp[MAX_ID_LENGTH],
       *token = " ";

  scanf("%d", &n);
  getchar();

  if (n < 1 || n > MAX_STUDENTS) {
    return 1;
  } 

  for (i = 0; i < n; i++) {
    strcpy(list_names[i], fgets(names, sizeof(names), stdin));
    names[strcspn(names, "\n")] = '\0';

    if (strlen(names) > 40) {
      return 1;
    }
  }

  scanf("%d", &n);
  getchar();

  for (i = 0; i < n; i++) {
    strcpy(list_letters[i], fgets(ids_letters, sizeof(ids_letters), stdin));
    ids_letters[strcspn(ids_letters, "\n")] = '\0';
  }

  for (i = 0; i < n; i++) {
    token = strtok(list_letters[i], " ");

    student_id[i] = atoi(token);

    token = strtok(NULL, " ");
    token[strcspn(token, "\n")] = '\0';

    strcpy(student_fol_name[i], token);

    // usado para duplicar a string sem passar o ponteiro
    for (j = 0; list_names[student_id[i]][j] != '\0'; ++j) {
      student_id_tmp[j] = list_names[student_id[i]][j];
    }

    token = strtok(student_id_tmp, " ");

    if (strcmp(student_fol_name[i], "u") == 0) {
      token = strtok(NULL, " ");
      token[strcspn(token, "\n")] = '\0';
    }

    printf("%c\n", token[0]);
  }

  return 0;
}

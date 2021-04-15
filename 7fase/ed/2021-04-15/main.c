/*
Você foi incumbido da tarefa de criar um programa que utilize
uma lista encadeada para armazenar um conjunto de alunos.
Cada aluno possui uma matrícula (char[10]), nome (char [40]),
uma data de nascimento (struct Data vista em aula),
média geral de notas (float).
Sua implementação deve suportar os seguintes requisitos...
https://moodle-academico.uffs.edu.br/mod/assign/view.php?id=342435
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LIMIT 1000

/* structs */

typedef struct {
    int dia;
    int mes;
    int ano;
} Date;

struct aluno {
    char matricula[10];
    char nome[40];
    Date* nascimento;
    float media;
};

typedef struct aluno Aluno;

typedef struct {
    Aluno* head;
    Aluno* tail;
} List;


/* methods */

void menu() {

}

void print_date(Date* date) {
    printf("%d/%d/%d\n", date->dia, date->mes, date->ano);
}

void read_birth(Aluno* aluno) {
    aluno->nascimento = malloc(sizeof(Aluno));
    char input[LINE_LIMIT], day[2], month[2], year[4];
    char* token = malloc(sizeof(char) * LINE_LIMIT), key[2] = "/";
    int i;

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, key);
    aluno->nascimento->dia = atoi(token);
    token = strtok(NULL, key);
    aluno->nascimento->mes = atoi(token);
    token = strtok(NULL, key);
    aluno->nascimento->ano = atoi(token);
}

Aluno* insert(List* alunos) {
    Aluno* aluno = malloc(sizeof(Aluno));

    fgets(aluno->matricula, sizeof(aluno->matricula), stdin);
    aluno->matricula[strcspn(aluno->matricula, "\n")] = '\0';

    getchar();
    
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    // printf("%s\n", aluno->matricula);
    printf("%s - %s\n", aluno->matricula, aluno->nome);

    read_birth(aluno);

    print_date(aluno->nascimento);

    scanf("%f", &aluno->media);
    
    printf("%.2f\n", aluno->media);

    return aluno;
}


int main () {
    int n;
    List* alunos = malloc(sizeof(List));

    alunos->head = NULL;
    alunos->tail = NULL;

    scanf("%d\n", &n);

    insert(alunos);

    return 0;
}
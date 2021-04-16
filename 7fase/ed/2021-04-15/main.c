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

#define LINE_LIMIT 12

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
    struct aluno* next;
};

typedef struct aluno Aluno;

typedef struct {
    Aluno* head;
    Aluno* tail;
} List;


/* methods */

void menu() {

}

char* format_date(Date* date) {
    char* formatted = malloc(sizeof(char) * LINE_LIMIT);

    snprintf(formatted, sizeof(char) * LINE_LIMIT, "%d/%d/%d", date->dia, date->mes, date->ano);
    // printf("%d/%d/%d\n", date->dia, date->mes, date->ano);
    return formatted;
}

void print_aluno(Aluno* aluno) {
    printf("%s, %s, %s, %.2f\n",
        aluno->matricula,
        aluno->nome,
        format_date(aluno->nascimento),
        aluno->media
    );
}

void print_list(List* alunos) {
    if (alunos->head == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Aluno* aux = malloc(sizeof(Aluno));
    aux = alunos->head;

    print_aluno(aux);

    while (aux->next != NULL) {
        aux = aux->next;
        print_aluno(aux);
    }
}

void read_birth(Aluno* aluno) {
    aluno->nascimento = malloc(sizeof(Aluno));
    char input[LINE_LIMIT];
    char* token = malloc(sizeof(char) * LINE_LIMIT), key[2] = "/";

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

    read_birth(aluno);

    scanf("%f", &aluno->media);
    
    aluno->next = NULL;

    if (alunos->head == NULL) {
        alunos->head = aluno;
        alunos->tail = aluno;
    } else {
        Aluno* aux = malloc(sizeof(Aluno));
        aux = alunos->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }

        printf("%s\n", aluno->matricula);

        aux->next = aluno;
        alunos->tail = aluno;
    }

    return aluno;
}


int main () {
    int n;
    List* alunos = malloc(sizeof(List));

    alunos->head = NULL;
    alunos->tail = NULL;

    scanf("%d\n", &n);

    insert(alunos);
    
    scanf("%d\n", &n);
    
    insert(alunos);

    print_list(alunos);

    return 0;
}
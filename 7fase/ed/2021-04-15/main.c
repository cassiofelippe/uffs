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

#define LINE_LIMIT_DATE 12
#define LIMIT_MATRICULA 25 // TODO set to 10 and fix the code


/* structs */

typedef struct {
    int dia;
    int mes;
    int ano;
} Date;

struct aluno {
    char matricula[LIMIT_MATRICULA];
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

char* format_date(Date* date) {
    // printf("DEBUG >> format_date\n");
    int size = sizeof(char) * LINE_LIMIT_DATE;
    char* formatted = malloc(size);

    snprintf(formatted, size, "%d/%d/%d", date->dia, date->mes, date->ano);
    return formatted;
}

void print_aluno(Aluno* aluno) {
    // printf("DEBUG >> print_aluno\n");
    printf("%s, %s, %s, %.2f\n",
        aluno->matricula,
        aluno->nome,
        format_date(aluno->nascimento),
        aluno->media
    );
}

void print_list(List* alunos) {
    // printf("DEBUG >> print_list\n");
    if (alunos->head == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Aluno* aux = alunos->head;

    print_aluno(aux);

    while (aux->next != NULL) {
        aux = aux->next;
        print_aluno(aux);
    }
}

void print_list_inverted_pos(Aluno* aluno) {
    // printf("DEBUG >> print_list_inverted_pos\n");
    if (aluno == NULL) {
        return;
    }

    print_list_inverted_pos(aluno->next);

    print_aluno(aluno);
}

void print_list_inverted(List* list) {
    // printf("DEBUG >> print_list_inverted\n");
    if (list->head == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    print_list_inverted_pos(list->head);
}

void count(List* alunos) {
    // printf("DEBUG >> count\n");
    if (alunos->head == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Aluno* aux = alunos->head;
    int i = 0;

    while (aux != NULL) {
        aux = aux->next;
        i++;
    }

    printf("%d\n", i);
}

void free_and_quit_pos(Aluno* aluno) {
    // printf("DEBUG >> free_and_quit_pos\n");

    if (aluno == NULL) {
        return;
    }

    free_and_quit_pos(aluno->next);

    printf("-");

    free(aluno);
}

void free_and_quit(List* alunos) {
    // printf("DEBUG >> free_and_quit\n");
    if (alunos->head == NULL) {
        return;
    }

    free_and_quit_pos(alunos->head);

    printf("\n");
}

void read_birth(Aluno* aluno) {
    // printf("DEBUG >> read_birth\n");

    aluno->nascimento = malloc(sizeof(Aluno));
    char input[LINE_LIMIT_DATE];
    char* token = malloc(sizeof(char) * LINE_LIMIT_DATE), key[2] = "/";

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
    // printf("DEBUG >> insert\n");

    Aluno* aluno = malloc(sizeof(Aluno));

    fgets(aluno->matricula, sizeof(aluno->matricula), stdin);
    aluno->matricula[strcspn(aluno->matricula, "\n")] = '\0';

    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';
    
    read_birth(aluno);

    scanf("%f%*[^\n]", &aluno->media);
    getchar();
    
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

        aux->next = aluno;
        alunos->tail = aluno;
    }

    return aluno;
}

void delete(List* alunos) {
    // printf("DEBUG >> delete\n");
    if (alunos->head == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Aluno* prev = alunos->head;
    Aluno* curr = alunos->head;
    char matricula[LIMIT_MATRICULA];

    fgets(matricula, sizeof(matricula), stdin);
    matricula[strcspn(matricula, "\n")] = '\0';
    

    while (curr != NULL) {
        if (strcmp(matricula, curr->matricula) == 0) {
            /* se for o primeiro elemento */
            if (strcmp(alunos->head->matricula, matricula) == 0) {
                alunos->head = curr->next;
                free(curr);
                return;
            }

            /* se for o ultimo elemento */
            if (strcmp(alunos->tail->matricula, matricula) == 0) {
                prev->next = NULL;
                alunos->tail = prev;
                free(curr);
                return;
            }

            /* se estiver no meio da lista */
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void menu(List* alunos) {
    // printf("DEBUG >> menu\n");
    int option = -1;

    while (option != 0) {
        /*
        printf("\n\
- Opção 1: Incluir elemento na lista\n\
- Opção 2: Excluir elemento da lista\n\
- Opção 3: Listar todos os elementos da lista na ordem de inclusão\n\
- Opção 4: Listar todos os elementos da lista na ordem inversa a inclusão\n\
- Opção 5: Apresentar quantos elementos existem na lista\n\
- Opção 0: Sair do programa\n"
        );
        */

        scanf("%d%*[^\n]", &option);
        getchar();

        switch(option) {
            case 1: {
                insert(alunos);
                break;
            }

            case 2: {
                delete(alunos);
                break;
            }

            case 3: {
                print_list(alunos);
                break;
            }

            case 4: {
                print_list_inverted(alunos);
                break;
            }

            case 5: {
                count(alunos);
                break;
            }

            case 0: {
                free_and_quit(alunos);
                return;
            }

            default: {
                printf("bruh\n");
                return;
            }
        }
    }
}


int main() {
    List* alunos = malloc(sizeof(List));

    alunos->head = NULL;
    alunos->tail = NULL;

    menu(alunos);

    return 0;
}


/** references
tive problemas com o fgets e fiquei tempo parado nisso:
https://stackoverflow.com/questions/20150845/c-program-skips-fgets
https://stackoverflow.com/questions/26318275/fgets-skipping-inputs/26318321
(quando na verdade o tamanho da string matricula era pequeno e causava a maioria dos erros)

ideia de usar recursividade para resolver essa questão (print_list_inverted_pos) baseada na seguinte fonte:
https://www.geeksforgeeks.org/print-reverse-of-a-linked-list-without-actually-reversing/
*/
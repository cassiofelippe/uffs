/*
Você vai implementar um programa que simule o botão back (voltar) de um browser. As
entradas são endereços da Internet que foram acessados pelo usuário (sequência de
caracteres sem espaço) e o caractere B. Quando o caractere B for encontrado, o último
endereço acessado deve ser impresso. Caso não haja mais endereços para acessar, a
mensagem “Vazio” deve ser impressa.
O programa é encerrado com quando o caractere ‘E’. Neste ponto você deve limpar a pilha,
caso a pila tenha elementos imprima ‘@’ para cada elemento que você limpar. Caso o
programa acabe e a pilha já esteja vazia imprima ‘!’.

https://moodle-academico.uffs.edu.br/mod/assign/view.php?id=352162

1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE - 05/05/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LIMIT 62
#define INPUT_END "E"
#define INPUT_POP "B"


/* structs */

struct line {
    char url[INPUT_LIMIT];
    struct line* prev;
};

typedef struct line Line;

typedef struct {
    Line* top;
} Stack;


/* methods */

void pop(Stack* history) {
    Line* aux = history->top;

    if (aux == NULL) {
        printf("Vazio\n");
        return;
    }

    printf("%s\n", aux->url);

    history->top = aux->prev;

    free(aux);
}

void free_and_print_history(Stack* history) {
    if (history->top == NULL) {
        printf("!\n");
        return;
    }

    int count = 0, i;

    while (history->top != NULL) {
        Line* aux = history->top;

        history->top = aux->prev;
        free(aux);

        count++;
    }

    for (i = 0; i < count; i++) {
        printf("@");
    }
    
    printf("\n");
}

void init(Stack* history) {
    Line* aux;

    /* runs until the input is different than "E" */
    do {
        aux = malloc(sizeof(Line));
        aux->prev = history->top;

        scanf("%s", aux->url);

        if (strcmp(aux->url, "E") == 0) {
            free(aux);
            break;
        }

        if (strcmp(aux->url, "B") == 0) {
            pop(history);
        } else {
            history->top = aux;
        }

    } while (1);

    free_and_print_history(history);
}


int main() {
    Stack* history = malloc(sizeof(Stack));

    history->top = NULL;

    init(history);

    free(history);

    return 0;
}

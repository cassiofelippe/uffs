#include <stdio.h>

typedef struct {
    char vet[112];
    int topo;
} Pilha_char;

void init_pilha(Pilha_char *p)
{
    p->topo = -1;
}

void push(Pilha_char *p, char c)
{
    p->vet[++p->topo] = c;
}

char pop(Pilha_char *p)
{
    return p->vet[p->topo--];
}

int main()
{
    char str[1123];
    Pilha_char p;
    int i, j;

    printf("Frase:\n");
    fgets(str, 1123, stdin);

    init_pilha(&p);
    for(i = j = 0; str[i]; i++){
        if(str[i] == ' ' || str[i] == '\n'){
            while(str[j] != ' ' && str[j] != '\n'){
                str[j++] = pop(&p);
            }
            j++;
        } else {
            push(&p, str[i]);
        }
    }
    printf("%s", str);

    return 0;
}
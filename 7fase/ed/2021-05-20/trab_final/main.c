/*
https://moodle-academico.uffs.edu.br/mod/assign/view.php?id=357812

1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
1621101031 - LUCAS CLAUDIO TISSOTI

20/05/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação
#define LINE_LIMIT_DATE 12


//Struct que representa a data.
typedef struct {
	int day;
	int month;
	int year;
} Date;

// Estrutura que contém os campos dos registros da agenda
struct MREC {
    char name[30];
    Date *birth; 
    char email[40];
    char phone[15];
    struct MREC *next;
    struct MREC *prev;
};

// Tipo criado para instanciar variáveis do tipo agenda
typedef struct MREC Contact;

typedef struct {
    Contact* head;
    Contact* tail;
} CBook;


/* METHODS */

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu() {
    int op = EXIT+1;

    scanf("%d", &op);
    
    // while (op != EXIT) {
    //     printf("%d Finaliza", EXIT);
    //     printf("\n: ");
    //     scanf("%d", &op);
    // }

    return op;
}

void insDate(Contact* contact) {
    contact->birth = malloc(sizeof(Contact));

    char input[LINE_LIMIT_DATE];
    char* token = malloc(sizeof(char) * LINE_LIMIT_DATE), key[2] = "/";

    scanf("%s", input);

    token = strtok(input, key);
    contact->birth->day = atoi(token);
    token = strtok(NULL, key);
    contact->birth->month = atoi(token);
    token = strtok(NULL, key);
    contact->birth->year = atoi(token);
}

// Permite o cadastro de um contato
void insContact(CBook* book) {
    printf("DEBUG >> insContact\n");

    Contact *newContact = malloc(sizeof(Contact));
    newContact->next = NULL;
    newContact->prev = NULL;

    // fgets(newContact->name, sizeof(newContact->name), stdin);
    // newContact->name[strcspn(newContact->name, "\n")] = '\0';
    scanf("%s", newContact->name);

    insDate(newContact);

    // fgets(newContact->email, sizeof(newContact->email), stdin);
    // newContact->email[strcspn(newContact->email, "\n")] = '\0';
    scanf("%s", newContact->email);

    // fgets(newContact->phone, sizeof(newContact->phone), stdin);
    // newContact->phone[strcspn(newContact->phone, "\n")] = '\0';
    scanf("%s", newContact->phone);


    if (book->tail == NULL) {
        book->head = newContact;
        book->tail = newContact;
    } else {
        newContact->prev = book->tail;
        book->tail = newContact;
        newContact->prev->next = newContact;
    }

    return;
}

// Permite o cadastro de um contato
// deve ser passado pelo menos o email
void insContactAfter(CBook* book) {
    return;
}

// Permite excluir um contato da agenda baseado no email
void delContact(char *email) {
    return;
}

char* formatDate(Date* date) {
    // printf("DEBUG >> format_date\n");
    int size = sizeof(char) * LINE_LIMIT_DATE;
    char* formatted = malloc(size);

    int day = date->day, month = date->month;

    snprintf(
        formatted, size, "%s%d/%s%d/%d",
        day < 10 ? "0" : "", day,
        month < 10 ? "0" : "", month,
        date->year
    );

    return formatted;
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts(CBook* book) {
    printf("DEBUG >> listContacts\n");

    if (book->head == NULL) {
        return;
    }

    Contact* aux = book->head;

    while (aux != NULL) {
        printf("%s, %s, %s, %s\n",
        // printf("%s, %s, %s\n",
            aux->name,
            formatDate(aux->birth),
            aux->email,
            aux->phone
        );

        aux = aux->next;
    }

    return;
}

// Permite consultar um contato da agenda por nome
void queryContact(char *name) {
    return;
}

// Permite a atualização dos dados de um contato da agenda
void upContact() {
    return;
}

void freeMem() {
    return;
}

// Programa principal
int main() {
    int op = EXIT+1;
    
    CBook* book = malloc(sizeof(CBook));
    book->head = NULL;
    book->tail = NULL;

    while (op != EXIT) {
        op = menu();
        switch(op) {
            case 1: {
                insContact(book);
                break;
            }
            case 2: {
                insContactAfter(book);
                break;
            }
            case 3: {
                delContact(book->head->email);
                break;
            }
            case 4: {
                upContact();
                break;
            }
            case 5: {
                queryContact(book->head->email);
                break;
            }
            case 6: {
                listContacts(book);
                break;
            }
        }
    }

    freeMem(); // liberar toda a memória alocada
    
    return 0;
}

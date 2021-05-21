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
#define false 0
#define true 1


/* STRUCTS AND DATA TYPES */

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

typedef int boolean;


/* METHODS */

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

Contact* readContact() {
    Contact* newContact = malloc(sizeof(Contact));
    newContact->next = NULL;
    newContact->prev = NULL;

    // fgets(newContact->name, sizeof(newContact->name), stdin);
    // newContact->name[strcspn(newContact->name, "\n")] = '\0';
    scanf("%s", newContact->name);

    insDate(newContact);

    // fgets(newContact->email, sizeof(newContact->email), stdin);
    // newContact->email[strcspn(newContact->email, "\n")] = '\0';
    scanf("%s", newContact->email); // TODO o email inserido não pode existir na agenda

    // fgets(newContact->phone, sizeof(newContact->phone), stdin);
    // newContact->phone[strcspn(newContact->phone, "\n")] = '\0';
    scanf("%s", newContact->phone);

    return newContact;
}

// Permite o cadastro de um contato
void insContact(CBook* book) {
    // printf("DEBUG >> insContact\n");

    Contact *newContact = readContact();

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
    char email[40];
    
    printf("Insert the email: ");
    scanf("%s%*[^\n]", email);
    getchar();

    boolean found = false;

    Contact* aux = book->head;
    Contact* newContact = readContact();

    while (!found && aux != NULL) {
        if (strcmp(aux->email, email) == 0) {
            found = true;
            break;
        }

        aux = aux->next;
    }

    printf("\n%s found? %d\n", email, found);

    if (found) {
        /* caso tenha encontrado registro para email inserido */
        newContact->prev = aux;
        newContact->next = aux->next;
        aux->next = newContact;

        /* caso o registro encontrado seja o último da lista */
        if (newContact->next != NULL) {
            newContact->next->prev = newContact;
        }
    } else {
        /* caso não tenha encontrado */
        aux = book->head;

        if (aux == NULL) {
            /* se a lista estiver vazia */
            book->head = newContact;
            book->tail = newContact;
        } else {
            /* insere no começo da lista */
            newContact->next = aux;
            aux->prev = newContact;
            book->head = newContact;
        }
    }
}

// Permite excluir um contato da agenda baseado no email
void delContact(char *email) {
    return;
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts(CBook* book) {
    // printf("DEBUG >> listContacts\n");

    if (book->head == NULL) {
        return;
    }

    Contact* aux = book->head;

    while (aux != NULL) {
        printf("%s, %s, %s, %s\n",
            aux->name,
            formatDate(aux->birth),
            aux->email,
            aux->phone
        );

        aux = aux->next;
    }
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

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu(CBook* book) {
    int op;

    while (op != EXIT) {
        printf("\
************************************\n\
*              MENU                *\n\
************************************\n\
* [1] Insert contact at the end    *\n\
* [2] Insert contact after another *\n\
* [3] Delete contact               *\n\
* [4] Update contact               *\n\
* [5] Find contact by name         *\n\
* [6] List all contacts            *\n\
************************************\n"
        );

        printf("Please insert the desired option: ");
        
        scanf("%d%*[^\n]", &op);
        getchar();

        switch(op) {
            case 1: {
                printf("\n");
                insContact(book);
                printf("\n");
                break;
            }
            case 2: {
                printf("\n");
                insContactAfter(book);
                printf("\n");
                break;
            }
            case 3: {
                printf("\n");
                delContact(book->head->email);
                printf("\n");
                break;
            }
            case 4: {
                printf("\n");
                upContact();
                printf("\n");
                break;
            }
            case 5: {
                printf("\n");
                queryContact(book->head->email);
                printf("\n");
                break;
            }
            case 6: {
                printf("\n");
                listContacts(book);
                printf("\n");
                break;
            }
            case 10: {
                return 0;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }
    }

    return op;
}

// Programa principal
int main() {
    CBook* book = malloc(sizeof(CBook));
    book->head = NULL;
    book->tail = NULL;

    menu(book);

    freeMem(); // liberar toda a memória alocada
    
    return 0;
}

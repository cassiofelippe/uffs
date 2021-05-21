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

/* procura na agenca se já existe registro com o email */
Contact* searchByEmail(CBook* book, char* email) {
    Contact* aux = book->head;    
    boolean found = false;

    while (!found && aux != NULL) {
        if (strcmp(aux->email, email) == 0) {
            found = true;
            break;
        }

        aux = aux->next;
    }

    if (found) {
        return aux;
    }

    return NULL;
}

boolean emailAlreadyExist(CBook* book, Contact* newContact) {
    if (searchByEmail(book, newContact->email) != NULL) {
        printf("Email already exists! Returning to menu...\n");
        free(newContact);
        return true;
    }

    return false;
}

/* recebe o input do usuário */
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

    if (emailAlreadyExist(book, newContact)) {
        return;
    }

    if (book->tail == NULL) {
        book->head = newContact;
        book->tail = newContact;
    } else {
        newContact->prev = book->tail;
        book->tail = newContact;
        newContact->prev->next = newContact;
    }
}

// Permite o cadastro de um contato
// deve ser passado pelo menos o email
void insContactAfter(CBook* book) {
    char email[40];
    
    printf("Insert the email: ");
    scanf("%s%*[^\n]", email);
    getchar();

    Contact* newContact = readContact();

    if (emailAlreadyExist(book, newContact)) {
        return;
    }

    Contact* aux = searchByEmail(book, email);
    boolean found = aux != NULL;

    printf("found: %d, name: %s\n", found, aux->name);

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
void delContact(CBook* book) {
    Contact* aux = book->head;
    char email[40];
    
    printf("Insert the email: ");
    scanf("%s%*[^\n]", email);
    getchar();

    while (aux != NULL) {
        if (strcmp(aux->email, email) == 0) {
            /* caso seja o primeiro */
            if (book->head == aux) {
                /* caso seja o primeiro e último */
                if (book->tail == aux) {
                    book->head = NULL;
                    book->tail = NULL;
                } else {
                    book->head = aux->next;
                }
        
                free(aux);
                break;
            /* caso seja o último */
            } else if (book->tail == aux) {
                aux->prev->next = NULL;
                book->tail = aux->prev;
                free(aux);
                break;
            }

            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            break;
        }

        aux = aux->next;
    }
    
}

void printContact(Contact* contact) {
    printf("%s, %s, %s, %s\n",
        contact->name,
        formatDate(contact->birth),
        contact->email,
        contact->phone
    );
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts(CBook* book) {
    // printf("DEBUG >> listContacts\n");

    if (book->head == NULL) {
        return;
    }

    Contact* aux = book->head;

    while (aux != NULL) {
        printContact(aux);

        aux = aux->next;
    }
}

// Permite consultar um contato da agenda por nome
void queryContact(CBook* book) {
    Contact* aux = book->head;
    char name[30];
    
    printf("Insert the name: ");
    scanf("%s%*[^\n]", name);
    getchar();

    while (aux != NULL) {
        if (strcmp(aux->name, name) == 0) {
            printContact(aux);
        }

        aux = aux->next;
    }
}

// Permite a atualização dos dados de um contato da agenda
void upContact(CBook* book) {
    Contact* aux = book->head;
    char email[40];
    
    printf("Insert the email: ");
    scanf("%s%*[^\n]", email);
    getchar();

    while (aux != NULL) {
        if (strcmp(aux->email, email) == 0) {
            // fgets(newContact->name, sizeof(newContact->name), stdin);
            // newContact->name[strcspn(newContact->name, "\n")] = '\0';
            scanf("%s", aux->name);

            insDate(aux);

            // fgets(newContact->phone, sizeof(newContact->phone), stdin);
            // newContact->phone[strcspn(newContact->phone, "\n")] = '\0';
            scanf("%s", aux->phone);
            break;
        }

        aux = aux->next;
    }
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

        printf("\n");
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
                delContact(book);
                break;
            }
            case 4: {
                upContact(book);
                break;
            }
            case 5: {
                queryContact(book);
                break;
            }
            case 6: {
                listContacts(book);
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
        printf("\n");
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


/*
TODOs:
- trocar scanf para fgets em strings (com exceção da data que tá ok)
- testar ./main < input
- criar validação para email já existente
- testar todas as possibilidades para todo e cada método
*/
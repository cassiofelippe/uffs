#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 41
#define EVER 1


/* TYPES */

typedef struct {
	int day;
	int month;
	int year;
} Date;

struct employee {
	int id;
	char name[TAM_NOME];
	double salary;
	Date *birthdate;
	struct employee *prev;
	struct employee *next;
};

typedef struct employee Employee;

/* DEF METHODS */

void print_employee(Employee *emp);
void print_all_employees(Employee *emp);
void print_date(Date *date);
char* format_date(Date *date);
void scan_date(Date *date);
Employee* get_first_employee(Employee *emp);
Employee delete_employee(Employee *emp);

/* MAIN */

int main() {
	int n_records, i, test;

	Employee *aux = malloc(sizeof(Employee));
	aux->id = 0;
	aux->prev = NULL;
	aux->next = NULL;
	
	printf("How many records would you like to insert?\n");
	scanf("%d\n", &n_records);

	for (i = 1; i <= n_records; i++) {
		Employee *emp = malloc(sizeof(Employee));
		emp->birthdate = malloc(sizeof(Date));

		emp->id = i;

		printf("\nInsert the name of the employee: ");
		fgets(emp->name, sizeof(emp->name), stdin);
		emp->name[strcspn(emp->name, "\n")] = '\0';
		scan_date(emp->birthdate);
		printf("\nInsert the salary: ");
		scanf("%lf", &emp->salary);
		// sets previous as NULL when is the first record (id 0)
		emp->prev = aux->id > 0 ? aux : NULL;
		emp->next = NULL;

		aux->next = emp;
		aux = emp;
	
		scanf("\n");
	}

	aux = get_first_employee(aux);

	print_all_employees(aux);

	free(aux);

	return 0;
}

/* METHODS */

char* format_date(Date *date) {
	char *formatted_date = malloc(sizeof(char) * 10);

	sprintf(formatted_date,
		"%d/%d/%d",
		date->day,
		date->month,
		date->year
	);

	return formatted_date;
}

void print_date(Date *date) {
	printf("%s\n", format_date(date));
}

void print_employee(Employee *emp) {
	printf("\n\
*        ID: %d\n\
*      NAME: %s\n\
* BIRTHDATE: %s\n\
*    SALARY: %.2f",
		emp->id,
		emp->name,
		format_date(emp->birthdate),
		emp->salary,
		emp->prev != NULL ? emp->prev->id : -1
	);
	printf("\n**************************");
}

void print_all_employees(Employee *emp) {
	printf("\n**************************");
	printf("\n*   List of Employees    *");
	printf("\n**************************");

	// print all starting by the first inserted
	for (;EVER;) {
		print_employee(emp);
	
		if (emp->next == NULL) {
			break;
		}

		emp = emp->next;
	}
}

void scan_date(Date *date) {
	printf("\nBirthdate. Insert...\n");
	printf("Day: ");
	scanf("%d", &date->day);
	printf("Month: ");
	scanf("%d", &date->month);
	printf("Year: ");
	scanf("%d", &date->year);
}

Employee* get_first_employee(Employee *emp) {
	// get the first inserted
	for (;EVER;) {
		emp = emp->prev;
		if (emp->prev == NULL) {
			break;
		}
	}
	
	return emp;
}
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
Employee* delete_employee(int id, Employee *emp);

/* MAIN */

int main() {
	int n_records, i;

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

	print_all_employees(get_first_employee(aux));
	
	printf("\nWhich one do you want to delete?\n");
	scanf("%d\n", &n_records);

	aux = delete_employee(n_records, aux);

	printf("\nreturned first employee: %d\n", aux->id);

	print_all_employees(get_first_employee(aux));

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
		emp->salary
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
		if (emp->prev == NULL) {
			break;
		} else {
			emp = emp->prev;
		}
	}
	
	return emp;
}

Employee* delete_employee(int id, Employee *emp) {
	Employee *first = get_first_employee(emp);
	Employee *last = malloc(sizeof(Employee)), *delete = malloc(sizeof(Employee));

	emp = first;

	for (;EVER;) {
		if (emp->id == id) {
			delete = emp;
		}

		if (emp->next == NULL) {
			last = emp;
			break;
		}

		emp = emp->next;
	}

	if (first->id == delete->id) {
		delete->next->prev = NULL;
		first = delete->next;
	} else if (last->id == delete->id) {
		delete->prev->next = NULL;
	} else {
		delete->prev->next = delete->next;
	}

	free(delete);
	
	return first;
}
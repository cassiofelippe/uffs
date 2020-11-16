#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 41

int EVER = 1;

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
	struct employee *next;
};

typedef struct employee Employee;

/* DEF METHODS */

void print_employee(Employee *emp);
void print_date(Date *date);
char* format_date(Date *date);
void scan_date(Date *date);

/* MAIN */

int main() {

	Employee *boss = malloc(sizeof(Employee));
	Employee *last = malloc(sizeof(Employee));
	Date *boss_birthdate = malloc(sizeof(Date));

	int add_another = 1;

	boss_birthdate->day = 31;
	boss_birthdate->month = 1;
	boss_birthdate->year = 1993;

	boss->id = 1;
	snprintf(boss->name, TAM_NOME, "%s", "Pafuncio");
	boss->salary = 15423.56;
	boss->birthdate = boss_birthdate;
	boss->next = NULL;

	last = boss;

	while (add_another) {
		printf("\nWant to add another employee? (1 for YES, 0 for NO)\n");
		scanf("%d\n", &add_another);


		if (add_another) {
			Employee *emp = malloc(sizeof(Employee));
			emp->birthdate = malloc(sizeof(Date));

			emp->id = last->id + 1;

			printf("\nInsert the name of the employee: ");
			fgets(emp->name, sizeof(emp->name), stdin);
			emp->name[strcspn(emp->name, "\n")] = '\0';
			scan_date(emp->birthdate);
			printf("Insert the salary: ");
			scanf("%lf", &emp->salary);
			emp->next = NULL;

			last->next = emp;
			last = emp;
		}
	}

	printf("\n**************************");
	printf("\n*   List of Employees    *");
	printf("\n**************************");
	
	Employee *emp = boss;

	for (;EVER;) {
		if (emp->next == NULL) {
			EVER = 0;
		}

		print_employee(emp);
		emp = emp->next;
	}

	printf("\n**************************");

	free(boss);
	free(boss_birthdate);

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
}

void scan_date(Date *date) {
	printf("\nBirthdate. Insert...");
	printf("\nDay: ");
	scanf("%d", &date->day);
	printf("Month: ");
	scanf("%d", &date->month);
	printf("Year: ");
	scanf("%d", &date->year);
}

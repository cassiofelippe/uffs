#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int id;
	char nome[41];
	double salario;
	Date *birthdate;
} Employee;

void print_emp_birthdate(Employee *emp);

void compare_dates(Date *one, Date *two, int *result);

int main() {
	Date *birth = malloc(sizeof(Date));
	Employee *emp = malloc(sizeof(Employee));

	scanf("%d", &emp->birthdate->day);
	scanf("%d", &emp->birthdate->month);
	scanf("%d", &emp->birthdate->year);

	print_emp_birthdate(emp);

	free(birth);
	free(emp);
}

void print_emp_birthdate(Employee *emp) {
	printf(
		"Employee birthdate %d/%d/%d\n",
		emp->birthdate->day,
		emp->birthdate->month,
		emp->birthdate->year
	);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id_count = 1;

typedef struct {
    int day;
    int month;
    int year;
} Date;

struct employee {
    int id;
    char name[41];
    double salary;
    Date *birthdate;
    struct employee *next;
};

typedef struct employee Employee;

void populate(Employee *e) {
    e->id = id_count;
    
    snprintf(e->name, sizeof(e->name), "%s %d", "Employee nº", e->id);
    
    e->salary = 500.00;
    
    Date *birth = malloc(sizeof(Date));
    birth->day = 15;
    birth->month = 5;
    birth->year = 1998;
    e->birthdate = birth;

    e->next = NULL;

    id_count++;
}

Employee* insert(Employee* first) {
    while (first->next != NULL) {
        first = first->next;
    }

    Employee *e = malloc(sizeof(Employee));

    populate(e);

    first->next = e;

    return e;
}

void print_all(Employee* first) {
    while (first != NULL) {
        printf("\n");
        printf("id: %d\n", first->id);
        printf("name: %s\n", first->name);
        printf("salary: %.2lf\n", first->salary);
        printf("birth: %d/%d/%d\n", first->birthdate->day, first->birthdate->month, first->birthdate->year);
        first = first->next;
    }
}

int main() {
    Employee *first = malloc(sizeof(Employee));

    populate(first);

    insert(first);
    insert(first);

    print_all(first);
}
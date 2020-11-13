#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

void get_day(Date *one, int *result);

void compare_dates(Date *one, Date *two, int *result);

int main() {
	Date *one = malloc(sizeof(Date)), *two = malloc(sizeof(Date));
	int *result = malloc(sizeof(int));

	scanf("%d", &one->day);
	scanf("%d", &one->month);
	scanf("%d", &one->year);

	scanf("%d", &two->day);
	scanf("%d", &two->month);
	scanf("%d", &two->year);

	get_day(one, result);

	printf("day one %d\n", *result);

	get_day(two, result);

	printf("day two %d\n", *result);

	compare_dates(one, two, result);

	printf("comparation %d\n", *result);

	free(one);
	free(two);
	free(result);
}

void get_day(Date *one, int *result) {
	*result = one->day;
}

/* returns:
	1 if the first date is older
 -1 if the first date is newer
	0 if it's the same
*/
void compare_dates(Date *one, Date *two, int *result) {
	if (one->year > two->year) {
		*result = -1;
	} else if (one->year < two->year) {
		*result = 1;
	}

	if (one->month > two->month) {
		*result = -1;
	} else if (one->month < two->month) {
		*result = 1;
	}

	if (one->day > two->day) {
		*result = -1;
	} else if (one->day < two->day) {
		*result = 1;
	} else {
		*result = 0;
	}
}
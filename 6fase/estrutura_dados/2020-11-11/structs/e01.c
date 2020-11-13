#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

int get_day(Date *birth);

int compare_dates(Date *one, Date *two);

int main() {
	Date *birth = malloc(sizeof(Date)), *other = malloc(sizeof(Date));
	int result;

	scanf("%d", &birth->day);
	scanf("%d", &birth->month);
	scanf("%d", &birth->year);

	printf("%d\n", get_day(birth));

	scanf("%d", &other->day);
	scanf("%d", &other->month);
	scanf("%d", &other->year);

	result = compare_dates(birth, other);

	printf("%d\n", result);
}

int get_day(Date *birth) {
	return birth->day;
}

/* returns:
	1 if the first date is older
 -1 if the first date is newer
	0 if it's the same
*/
int compare_dates(Date *one, Date *two) {
	if (one->year > two->year) {
		return -1;
	} else if (one->year < two->year) {
		return 1;
	}

	if (one->month > two->month) {
		return -1;
	} else if (one->month < two->month) {
		return 1;
	}

	if (one->day > two->day) {
		return -1;
	} else if (one->day < two->day) {
		return 1;
	} else {
		return 0;
	}
}
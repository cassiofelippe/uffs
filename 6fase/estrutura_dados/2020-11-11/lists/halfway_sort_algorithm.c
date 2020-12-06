#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVER 1
#define N 4

/* TYPES */

struct integer {
	int value;
	struct integer *prev;
	struct integer *next;
};

typedef struct integer Integer;

/* DEF METHODS */

void print_all(Integer *a);
void sort(Integer *num, int i);
Integer* get_first(Integer *num);

/* MAIN */

int main() {
	const int n = N;
	int a[N] = {1, 21, 4, 6}, i;
	Integer ints[N];

	for (i = 0; i < N; i++) {
		Integer *num = malloc(sizeof(Integer));
		
		num->value = a[i];

		if (i == 0) {
			num->prev = NULL;
		} else if (i == N - 1) {
			num->next = NULL;
			num->prev = &ints[i - 1];
			num->prev->next = num;
		} else {
			num->prev = &ints[i - 1];
			num->prev->next = num;
		}

		ints[i] = *num;
	}

	print_all(ints);

	sort(ints, 0);

	print_all(ints);

	return 0;
}

/* METHODS */

void print_all(Integer *a) {
	int i;
	printf("\n");
	for (i = 0; i < N; i++) {
		Integer *num = &a[i];

		printf("%d\t<\t%d\t>\t%d\n",
			num->prev == NULL ? -1 : num->prev->value,
			num->value,
			num->next == NULL ? -1 : num->next->value
		);
	}
	printf("\n");
}

void sort(Integer *ints, int i) {
	printf("\nsorting %d", ints[i].value);
	int j = i - 1;
	if (ints[i].prev == NULL) {
		return sort(ints, ++i);
	}

	if (ints[i].value < ints[j].value) {
		Integer *aux = &ints[j];
		ints[j].prev = &ints[i];
		ints[j].next = ints[i].next;
		ints[i].prev = aux->prev;
		ints[i].next = &ints[j];

		if (ints[i].next != NULL) {
			ints[j].next->prev = &ints[j];
		}

		if (ints[i].prev != NULL) {
			ints[i].prev->next = &ints[i];
		}

		printf("\nsorted %d", ints[i].value);
	} else {
		printf("\nskip %d", ints[i].value);
	}


	if (ints[i].next != NULL) {
		return sort(ints, ++i);
	}
}

Integer* get_first(Integer *num) {
	for (;EVER;) {
		if (num->prev == NULL) {
			break;
		}

		num = num-> prev;
	}

	return num;
}
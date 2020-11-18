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

Integer* build_list(const int n, int *v);
void print_all(Integer *first);

/* MAIN */

int main() {
	const int n = N;
	int v[N] = {1, 21, 4, 6};

	Integer *first = build_list(n, v);

	print_all(first);

	return 0;
}

/* METHODS */

Integer* build_list(const int n, int *v) {
	int i;
	Integer *first = malloc(sizeof(Integer));
	Integer *prev = malloc(sizeof(Integer));

	for (i = 0; i < n; i++) {
		Integer *aux = malloc(sizeof(Integer));

		if (i == 0) {
			aux->prev = NULL;
		} else {
			aux->prev = prev;
		}
		
		if (i > 0) {
			aux->prev->next = aux;
		}

		aux->value = v[i];
		aux->next = NULL;
		prev = aux;
	
		if (i == 0) {
			first = aux;
		}
	}

	return first;
}

void print_all(Integer *first) {
	printf("\n");
	for (;EVER;) {
		printf(" %d", first->value);

		if (first->next == NULL) {
			break;
		}

		first = first->next;
	}
	printf("\n");
}

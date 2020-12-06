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
void sort(Integer *first);
Integer* get_first(Integer *num);

/* MAIN */

int main() {
	const int n = N;
	int v[N] = {1, 21, 4, 6};

	Integer *first = build_list(n, v);

	print_all(get_first(first));

	sort(&first);

	print_all(get_first(first));

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

/* param num must be the first of the list */
void sort(Integer *num) {
	printf("\n\nbeen here for %d", *num->value);

	if (*num->prev == NULL) {
		return sort(&(*num)->next);
	} else if ((*num)->next == NULL) {
		return;
	}
	
	printf("\nprev %d", *num->prev->value);
	printf("\nnext %d", *num->next->value);
	

	// printf("\nprev %d | next %d", num->prev != NULL ? num->prev->value : -1, num->next->value);

	if (*num->prev->value > *num->value) {
		// memcpy(aux_copy, num->next, sizeof(Integer)); // deep copy, without referencing pointer
		// free(aux_copy);
		Integer *tmp = *num;

		tmp->prev = *num->prev;
		tmp->next->prev = tmp;

		*num = *num->prev;

		tmp->next = *num->next;
		*num->prev->prev = *num->prev;
		*num->prev->next = *num->next;

		*num->prev = tmp->prev;
		*num->next = tmp;

		// printf("\n>> prev %d | next %d", num->prev != NULL ? num->prev->value : -1, num->next->value);

		return sort(&(*num));
	} else {
		return sort(&(*num)->next);
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
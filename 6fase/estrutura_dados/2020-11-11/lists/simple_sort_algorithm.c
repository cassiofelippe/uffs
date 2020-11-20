#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4 // length


/* DEF METHODS */

void sort(int *a, int i);
void print(int *a);

/* MAIN */

int main() {
	int a[N] = {1, 21, 4, 6};

	printf("\nbefore:");
	print(a);

	sort(a, 1);

	printf("\nsorted:");
	print(a);

	printf("\n");

	return 0;
}

void sort(int *a, int i) {
	int aux, j = i - 1;

	if (i == 0) {
		return sort(a, i + 1);
	} else if (i == N) {
		return;
	}

	if (a[j] > a[i]) {
		aux = a[i];
		a[i] = a[j];
		a[j] = aux;
		return sort(a, 1);
	}

	return sort(a, i + 1);
}

void print(int *a) {
	int i;
	for (i = 0; i < N; i++) {
		printf(" %d", a[i]);
	}
}

#include <stdio.h>
#include <stdlib.h>


#define SIZE 3


void sort(int *v, int size, int i) {
	int aux;

	if (size - 1 == i) {
		return;
	}

	if (v[i] > v[i + 1]) {
		aux = v[i];
		v[i] = v[i + 1];
		v[i + 1] = aux;

		sort(v, size, 0);
	} else {
		sort(v, size, ++i);
	}
}

void print(int *v, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d\n", v[i]);
	}
}

void sort_and_print(int *v, int size) {
	sort(v, size, 0);

	print(v, size);
}


int main() {
	int size = SIZE, i, *inputs = malloc(sizeof(int)*size);

	for (i = 0; i < size; i++) {
		scanf("%d", &inputs[i]);
	}

	sort_and_print(inputs, size);

	return 0;
}


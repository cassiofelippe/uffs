#include <stdio.h>
#include <stdlib.h>


#define SIZE 9


int list[SIZE] = {7, 10, 5, 3, 8, 4, 2, 9, 6};

void print_list() {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d ", i);
	}
}

void _static() {
	int i, j, aux;

	for (i = 0; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			aux = list[j];

			if (j >= SIZE) {
				break;
			}

			if (list[i] > list[j]) {
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}

	print_list();
}

int main() {

	_static();

	return 0;
}
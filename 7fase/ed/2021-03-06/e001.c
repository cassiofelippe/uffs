#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define LINE 100

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
	int *copy = malloc(sizeof(int) * size), i;

	for (i = 0; i < size; i++) {
		copy[i] = v[i];
	}

	sort(copy, size, 0);

	print(copy, size);

	printf("\n");

	print(v, size);
}


int main() {
	int size = SIZE, *inputs = malloc(sizeof(int) * size), n, i;
	char *line = malloc(sizeof(char) * LINE), *token, c[2] = " ";

    fgets(line, sizeof(line) + 1, stdin);
    line[strcspn(line, "\n")] = '\0';

    token = strtok(line, c);

    /* convert line attributes to array items */
	for (i = 0; token != NULL; i++) {
    	n = (int) atoi(token);

    	inputs[i] = n;

		token = strtok(NULL, c);
	}

	sort_and_print(inputs, size);

	return 0;
}


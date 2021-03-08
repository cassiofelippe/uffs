/*
	URI #1175
	1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main() {
	int i, x, *input = malloc(sizeof(float) * SIZE);

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &input[i]);
	}

	for (i = 0; i < SIZE / 2; i++) {
		x = input[i];
		input[i] = input[SIZE - (i + 1)];
		input[SIZE - (i + 1)] = x;
	}

	for (i = 0; i < SIZE; i++) {
		printf("N[%d] = %d\n", i, input[i]);
	}

	return 0;
}

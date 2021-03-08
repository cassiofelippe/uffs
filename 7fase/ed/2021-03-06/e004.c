/*
	URI #1174
	1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
	int i;
	float *input = malloc(sizeof(float) * SIZE);

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &input[i]);
	}

	for (i = 0; i < SIZE; i++) {
		if (input[i] <= 10.0) {
			printf("A[%d] = %.1f\n", i, input[i]);
		}
	}

	return 0;
}

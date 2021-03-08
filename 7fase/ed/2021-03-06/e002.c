/*
	URI #1172
	1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
	int i, *input = malloc(sizeof(int) * SIZE);

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &input[i]);

		if (input[i] <= 0) {
			input[i] = 1;
		}

		printf("x[%d] = %d\n", i, input[i]);
	}

	return 0;
}

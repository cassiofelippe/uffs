/*
	URI #1177
	1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
	int i, j, x;

	scanf("%d", &x);

	if (x <= 2 || x > 50) {
		return 1;
	}

	for (i = 0, j = 0; i < SIZE; i++) {
		printf("N[%d] = %d\n", i, j);

		if (j < (x - 1)) {
			j++;
		} else {
			j = 0;
		}
	}

	return 0;
}

/*
	URI #1173
	1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
	int x, i;

	scanf("%d", &x);

	if (x > 50) {
		return 1;
	}

	for (i = 0; i < SIZE; i++) {
		printf("N[%d] = %d\n", i, x);
		x *= 2;
	}

	return 0;
}

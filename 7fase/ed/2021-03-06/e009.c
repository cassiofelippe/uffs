/*
    URI #1065
    1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main() {
	int x, i, even = 0;

    for (i = 0; i < SIZE; i++) {
	   scanf("%d", &x);

       if (x % 2 == 0) {
        even++;
       }
    }

    printf("%d valores pares\n", even);

	return 0;
}


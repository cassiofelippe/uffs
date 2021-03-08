/*
    URI #1151
    1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x, two_last[2] = {0, 1}, n, i;

	scanf("%d", &x);

	if (x <= 0 || x >= 46) {
		return 1;
	}

    printf("%d %d ", two_last[0], two_last[1]);

	for (i = 0; i < x; i++) {
        if (i > 1) {
            n = two_last[0] + two_last[1];
            
            printf("%d", n);
            
            two_last[0] = two_last[1];
            two_last[1] = n;

            if (i < x - 1) {
                printf(" ");
            }
        }
	}

    printf("\n");

	return 0;
}


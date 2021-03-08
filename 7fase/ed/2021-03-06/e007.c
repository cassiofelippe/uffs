/*
    URI #1180
    1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 10000

void print_minor(int *v, int size) {
	int i, minor, index;

	for (i = 0; i < size; i++) {
        if (i < size - 1 && v[i] > v[i + 1]) {
		  minor = v[i + 1];
          index = i + 1;
        }
	}

    printf("Menor valor: %d\n", minor);
    printf("Posicao: %d\n", index);
}

int main() {
	int x;

	scanf("%d\n", &x);

	if (x <= 1 || x >= 1000) {
		return 1;
	}

	int *input = malloc(sizeof(int) * x), n, i;
	char *line = malloc(sizeof(char) * LINE), *token = malloc(sizeof(char) * LINE), c[2] = " ";

    fgets(line, sizeof(line) + LINE, stdin);
    line[strcspn(line, "\n")] = '\0';

    token = strtok(line, c);

    /* convert line attributes to array items */
	for (i = 0; token != NULL; i++) {
    	n = (int) atoi(token);

    	input[i] = n;

		token = strtok(NULL, c);
	}

	print_minor(input, x);

	return 0;
}


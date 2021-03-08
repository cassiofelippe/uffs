#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 10000

void print(int *v, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d\n", v[i]);
	}
}

int main() {
	int x;

	scanf("%d", &x);

	if (x <= 1 || x > 1000) {
		return 1;
	}

	int *input = malloc(sizeof(int) * x), n, i;
	char *line = malloc(sizeof(char) * LINE), *token, c[2] = " ";

    fgets(line, sizeof(line) + 1, stdin);
    line[strcspn(line, "\n")] = '\0';

    token = strtok(line, c);

    /* convert line attributes to array items */
	for (i = 0; token != NULL; i++) {
    	n = (int) atoi(token);

    	printf("%d\n", n);

    	input[i] = n;

		token = strtok(NULL, c);
	}

	print(input, x);

	return 0;
}


/*
    URI #1059
    1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>

#define SIZE 100

int main() {
	int i;

  for (i = 1; i <= SIZE; i++) {
    if (i % 2 == 0) {
      printf("%d\n", i);
    }
  }

	return 0;
}


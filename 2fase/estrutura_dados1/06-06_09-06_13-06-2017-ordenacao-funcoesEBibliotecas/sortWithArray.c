#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort.h"
#include "functions.c"

int main() {
	int n, i;
	time_t t;

	printf("\nInsert the array size: ");
	scanf("%d", &n);

	int v[n];

	for(i = 0; i < n; i++){
		v[i] = rand() % 10;
	}

	printf("\narray before sort: ");
	for(i = 0; i < n; i++){
		printf(" %d ", v[i]);
	}

	insertionSort(n, v);

	printf("\narray after sort: ");
	for(i = 0; i < n; i++){
		printf(" %d ", v[i]);
	}

	printf("\n");
	return 0;
}
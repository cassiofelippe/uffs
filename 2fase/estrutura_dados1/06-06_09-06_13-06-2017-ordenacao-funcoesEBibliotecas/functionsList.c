#include <stdio.h>
#include "insertionSortArray.h"

void insertionSort(int n, int *v){
	int i, key;

	i = 0;
	while(i < n){
		if(i == 0){
			i++;
		}else	if(v[i] < v[(i-1)]){
			key = v[(i-1)];
			v[(i-1)] = v[i];
			v[i] = key;
			i--;
		}else if(v[i] >= v[(i-1)]){
			i++;
		}
	}
}
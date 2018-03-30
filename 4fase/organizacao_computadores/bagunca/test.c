#include <stdio.h>
#define MAX 50

#include <stdio.h>

int main(){
	float num, keep, result;
	int i, onlyInt;
	printf("INSERT THE NUMBER TO SEE HOW MANY NUMBERS AFTER DECIMAL POINT: ");
	scanf("%f", &num);

	keep = num - (int)num;
	result = (keep - (int)keep);

	// for(i = 0; i != 2;){
	for(i = 0; result == 0.000000;){
		keep = keep * 10;
		i++;
		printf("\nkeep: %.2f", keep);
		printf("\nintKeep: %d", (int)keep);
		result = (keep - (int)keep);
		// printf("\nresult: %lf", result);
		printf("\nresult > 0: %d", (result == 0.000000));
		printf("\ni: %d", i);
	}
}

#include <stdio.h>
#define MAX 50

int main(){
  float value = 0.0;
  printf("\nINSERT A DOUBLE VALUE: ");
  scanf("%f", &value);
  int num = (int)value;
  float decpart = value - num;

	int bin_int[MAX], original_int = num, i = 0, j;
	while(num > 0){
		bin_int[i] = num % 2;
		i++;
		num = num / 2;
	}
	printf("%d BINARY INT: ", original_int);
	for(j = i - 1; j >= 0; j--){
		printf("%d", bin_int[j]);
	}
	printf("\n");

	i = 0;
	int bin_dec[MAX], original_dec = decpart;
	while(decpart > 0){
		bin_dec[i] = decpart % 2;
		i++;
		decpart = decpart / 2;
	}
	printf("%d BINARY DEC: ", original_dec);
	for(j = i - 1; j >= 0; j--){
		printf("%d", bin_dec[j]);
	}
	printf("\n");




	return 0;
}
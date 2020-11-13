#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double real;
	double imaginary;
} Complex;

void set(double *a, double *b, Complex *number);

int main() {
	Complex *number = malloc(sizeof(Complex));
	double *a = malloc(sizeof(double)), *b = malloc(sizeof(double));

	scanf("%ld", a);
	scanf("%ld", b);

	set(a, b, number);

	printf("real %ld\n", number->real);
	printf("imag %ld\n", number->imaginary);

	free(number);
	free(a);
	free(b);
}

void set(double *a, double *b, Complex *number) {
	number->real = *a;
	number->imaginary = *b;
}

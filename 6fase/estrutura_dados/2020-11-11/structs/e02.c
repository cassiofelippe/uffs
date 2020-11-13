#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double real;
	double imaginary;
} Complex;

void set(double *a, double *b, Complex *number);

void sum_real_imag(Complex *a, Complex *b, Complex *sum);

int main() {
	Complex *number = malloc(sizeof(Complex)), *second = malloc(sizeof(Complex)), *sum = malloc(sizeof(Complex));
	double *a = malloc(sizeof(double)), *b = malloc(sizeof(double));

	scanf("%lf", a);
	scanf("%lf", b);

	set(a, b, number);

	scanf("%lf", a);
	scanf("%lf", b);

	set(a, b, second);

	sum_real_imag(number, second, sum);

	printf("sum real %lf\n", sum->real);
	printf("sum imag %lf\n", sum->imaginary);

	free(number);
	free(second);
	free(sum);
	free(a);
	free(b);
}

void set(double *a, double *b, Complex *number) {
	number->real = *a;
	number->imaginary = *b;
}


void sum_real_imag(Complex *a, Complex *b, Complex *sum) {
	sum->real = a->real + b->real;
	sum->imaginary = a->imaginary + b->imaginary;
}

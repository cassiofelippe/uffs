#include <stdio.h>
#include <stdlib.h>


struct complexo {
    double real;
    double imaginario;
};

typedef struct complexo Complexo;


Complexo* criaComplexo(double x, double y) {
    Complexo *numero = malloc(sizeof(Complexo));
    numero->real = x;
    numero->imaginario = y;

    return numero;
}

Complexo* somaComplexos(Complexo* x, Complexo* y) {
    Complexo *numero = malloc(sizeof(Complexo));
    numero->real = x->real + y->real;
    numero->imaginario = x->imaginario + y->imaginario;

    return numero;
}


int main() {
    Complexo *x = criaComplexo(1, 2);
    Complexo *y = criaComplexo(2, 4);
    Complexo *z = somaComplexos(x, y);

    printf("%lf\n", z->real);
    printf("%lf\n", z->imaginario);

    return 0;
}
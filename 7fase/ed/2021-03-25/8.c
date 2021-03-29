#include <stdio.h>

void funcao(int x, int *y) {
    x = 41 + 1;
    *y = 21 + 21;
}

int main() {
    int x, y;

    x = 1;

    y = 1;

    funcao(x, &y);

    x = x*x;


    printf("%d,%d\n", x, y);

    return 0;
}
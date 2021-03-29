#include <stdio.h>

int main(){
    int *n, x = 53, y = 1;

    n = &x;

    *n = 10;

    n = &y;

    x++;

    y -= 23;

    printf("%d,%d,%d\n", x, *n, y);

    return 0;
}
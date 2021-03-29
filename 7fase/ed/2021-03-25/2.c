#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int recursiva(int x) {
    if (x == 1) {
        return -x;
    }

    return -5 * recursiva(x - 1) + x;
}


int main() {
    int x = recursiva(4);

    printf("%d\n", x);
}
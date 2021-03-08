/*
    URI #1018
    1621101010 - CASSIO LUIS ZAMIGNAN FORTE FELIPPE
*/

#include <stdio.h>

#define SIZE 100

int main() {
    int notes[7] = {100, 50, 20, 10, 5, 2, 1},
        used[7] = {0, 0, 0, 0, 0, 0, 0}, n, i, value;

    scanf("%d", &value);

    printf("%d\n", value);

    for (i = 0; i < 7; i++) {
        n = notes[i];

        while (value - n >= (n - value)) {
            used[i]++;
            value -= n;
        }
    }

    for (i = 0; i < 7; i++) {
        printf("%d nota(s) de R$ %d,00\n", used[i], notes[i]);
    }

    return 0;
}


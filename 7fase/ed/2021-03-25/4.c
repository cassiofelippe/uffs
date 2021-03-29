#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {'t', 'e', 's', 't', 'i', 'n', 'h', 'o', '\0'};

    printf("1: %s :)\n", str);

    snprintf(str, 9, "2: %s", "Eitah");
    printf("2: %s\n", str);

    return 0;
}
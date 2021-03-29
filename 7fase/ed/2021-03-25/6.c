#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[42];

    fgets(string, sizeof(string), stdin);

    printf("String lida: %s", string);

    return 0;
}
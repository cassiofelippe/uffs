#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TSIZE 17; // preferível usar número primo


double hash(int value);
double insert(int value);


typedef struct HTable {
	int index;
	int value;
    int *next_index;
} HashTable;


int main() {

    // HashTable table = malloc(sizeof(HashTable));

    // scanf("%d", &value);

    insert(5);
    insert(6);
    insert(7);
    insert(10);
    insert(451);


    return 0;
}


double hash(int value) {
    return value % TSIZE;
}


double insert(int value) {
    double index = hash(value);
    
    printf("\n>> value: %d, index: %f\n", value, index);

    return index;
}

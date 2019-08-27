#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 4
#define WIDTH 5

void printMatriz(int *matriz){
	int i;
	for (i = 0; i < HEIGHT*WIDTH; ++i)
    {
    	if(i % WIDTH == 0)
    		printf("\n");
    	printf("%d ", *(matriz+i));
    }
}

int main()
{
    int table[HEIGHT][WIDTH] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    printf("Pointer \n");
    int *p1 = &table[0][0];
    printMatriz(p1);
    printf("\nPointer to Pointer\n");
    int **p2 = &table[0];
    printMatriz(p2);
    printf("\nPointer to Pointer to Pointer\n");
    int ***p3 = &table;
    printMatriz(p3);
    printf("\nMatriz\n");
    printMatriz(*table);
    return 0;
}
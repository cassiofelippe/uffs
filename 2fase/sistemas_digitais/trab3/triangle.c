#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"
#include "header.h"

#define Y 50
#define X 125

int main(){
	int graphic[X][X], i, j, x[3], y[3],
	xtriangle1, ytriangle1, xtriangle2, ytriangle2,
	xtriangle3, ytriangle3, xdod, ydod, area;

	printf("\nY max: %d, X max: %d\n", Y, X);

	printf("\nInsira o 1º x: ");
	scanf("%d", &xtriangle1);
	printf("\nInsira o 1º y: ");
	scanf("%d", &ytriangle1);
	printf("\nInsira o 2º x: ");
	scanf("%d", &xtriangle2);
	printf("\nInsira o 2º y: ");
	scanf("%d", &ytriangle2);
	printf("\nInsira o 3º x: ");
	scanf("%d", &xtriangle3);
	printf("\nInsira o 3º y: ");
	scanf("%d", &ytriangle3);
	
	int triangleArea = tri_area(xtriangle1, ytriangle1, xtriangle2, ytriangle2, xtriangle3, ytriangle3);
	printf("\nmain triangle area: %d\n\n", triangleArea);

	int eachTriangle;

	// X
	for(i = (Y); i >= 0; i--){
		// Y
		for(j = 0; j < X; j++){
			eachTriangle = dodInTriangle(xtriangle1, ytriangle1, xtriangle2, ytriangle2, xtriangle3, ytriangle3, j, i);
			if(triangleArea >= eachTriangle){
				printf("@");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}

	printf("\n\n");

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"
#include "header.h"

#define Y 50
#define X 125

int main(){
	int graphic[X][X], i, j, x[3], y[3],
	x1, y1, x2, y2, x3, y3, xdod, ydod, area;

	printf("\nY max: %d, X max: %d\n", Y, X);

	printf("\nInsert x1, y1, x2, y2, x3, y3, xdod, ydod (separated by spaces)\n");
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &xdod, &ydod);
	
	int triangleArea = tri_area(x1, y1, x2, y2, x3, y3);

	int eachTriangle = dodInTriangle(x1, y1, x2, y2, x3, y3, xdod, ydod);
	
	if(triangleArea >= eachTriangle){
		printf("\npoint is inside the triangle");
	}else{
		printf("\npoint is not inside the triangle");
	}

	printf("\n\n");

	return 0;
}

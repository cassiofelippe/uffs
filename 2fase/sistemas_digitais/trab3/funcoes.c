#include "header.h"

int tri_area(int x1, int y1, int x2, int y2, int  x3, int y3){
	int area = abs(((x1*y2)+(x2*y3)+(y1*x3))-((x3*y2)+(x2*y1)+(y3*x1)));

	return area;
}

int dodInTriangle(int x1, int y1, int x2, int y2, int  x3, int y3, int px, int py){									
	int a = tri_area(x1, y1, x2, y2, px, py);
	int b = tri_area(x2, y2, x3, y3, px, py);
	int c = tri_area(x3, y3, x1, y1, px, py);

	int totalArea = a + b + c;

	return totalArea;
}
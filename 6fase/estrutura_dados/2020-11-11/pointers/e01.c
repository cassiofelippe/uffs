#include <stdio.h>

void print(int ap, int a, int b, int c);

int main() {

	int a = 13, b = 27, c = 34, *ap = &a;

	print(*ap, a, b, c);

	*ap = c + 1;

	print(*ap, a, b, c);

	b = *ap + 1;
	
	print(*ap, a, b, c);

	ap = &c;

	print(*ap, a, b, c);
	
	return 0;
}

void print(int ap, int a, int b, int c) {
	printf("%d %d %d %d\n", ap, a, b, c);
}
#include <stdio.h>

int main(){
	int i, vnum[5];

	int *p1;

	p1 = vnum;	*p1 = 10;
	p1++;	*p1 = 20;
	p1 = &vnum[2]; *p1 = 30;
	p1 = vnum + 3; *p1 = 40;
	p1 = vnum; *(p1+4) = 50;

	for(i=0; i<5; i++){
		printf("%d\t", vnum[i]);
	}

	return 0;
}
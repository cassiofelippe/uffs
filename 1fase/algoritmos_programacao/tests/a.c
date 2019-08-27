#include <stdio.h>
#include <string.h>
void lbff(){
	char c;
	while(c = getchar() != '\n');
}
int main(void){
	char a[22], b[5];
	scanf("%[^\n]s");
	lbff();
	fgets(a, 22, stdin);
	a[strlen(a) -1] = '\0';
	fgets(b, 5, stdin);
	printf("%s", a);

}
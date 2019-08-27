#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.c"
#include "header.h"

#define MAX 50

typedef struct{
  char name[MAX];
  int phone;
  char email[MAX];
}Contact;

int main() {
	Contact contactStart[MAX] = {"", 0, ""};
	
	Contact *contact = contactStart;

	while(1){
		mainMenu(contact);
	}

	printf("\n\n");

	return 0;
}

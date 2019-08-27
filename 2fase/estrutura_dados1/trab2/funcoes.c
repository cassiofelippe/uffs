#include "header.h"

#define MAX 50

typedef struct{
  char name[MAX];
  int phone;
  char email[MAX];
}TContact;

void option1(TContact *contact){
	int i;
	for(i = 0; i < MAX; i++){
		if(contact[i].phone == 0){
			printf("\nInsert the name: ");
			scanf("%s", contact[i].name);

			printf("\nInsert the phone (only numbers): ");
			scanf("%d", &contact[i].phone);

			printf("\nInsert the email: ");
			scanf("%s", contact[i].email);
			break;

		}else{
			printf("\nStorage is full!\nYou might delete some contacts to be able to insert new ones\nReturning to main menu...");
			break;
		}
	}
}

void option2(TContact *contact){
	int option, i;
	printf("\nInsert the id of the contact to be removed: ");
	scanf("%d", &option);
	if(contact[option].phone == 0){
		printf("\nContact %d not found! Returning to main menu...", option);
	}else{
		printf("\nContact %d, %s removed!", option, contact[option].name);
		strcpy(contact[option].name, "");
		contact[option].phone = 0;
		strcpy(contact[option].email, "");
	}
}

void option3(TContact *contact){
	int id, i;
	system("clear");
	printf("\nInsert the id of the contact to be updated: ");
	scanf("%d", &id);
	for(i = 0; i < MAX; i++){
		if(i == id){
			printf("\nName: %s", contact[i].name);
			printf("\nPhone: %d", contact[i].phone);
			printf("\nEmail: %s", contact[i].email);
			printf("\n\n");
			printf("New name: ");
			scanf("%s", contact[i].name);
			printf("New phone: ");
			scanf("%d", &contact[i].phone);
			printf("New email: ");
			scanf("%s", contact[i].email);
			printf("\nContact updated!");
		}
	}
}

void option4(TContact *contact){
	int option, i;
	system("clear");
	printf("**************************\n");
	printf("* 1 - Quadratic method   *\n");
	printf("* 2 - Logarithmic method *\n");
	printf("* 0 - Back to main menu  *\n");
	printf("**************************\n");
	printf("Entry: ");
	scanf("%d", &option);

	switch(option){
		case 1:
			printf("\nEntered quadratic method...");
			break;

		case 2:
			printf("\nEntered logarithmic method...");
			break;

		case 0:
			printf("\nReturning to main menu...");
			break;

		default:
			printf("\nInvalid entry!");
			printf("\nReturning to main menu...");
	}
}

void option5(TContact *contact){
	int i;
	system("clear");
	for(i = 0; i < MAX; i++){
		if(contact[i].phone != 0){
			printf("Id: %d", i);
			printf("\nName: %s", contact[i].name);
			printf("\nPhone: %d", contact[i].phone);
			printf("\nEmail: %s", contact[i].email);
			printf("\n\n");
		}
	}
}

void option6(TContact *contact){
	int option, i;
	char busca[MAX];
	system("clear");
	printf("***************************\n");
	printf("* 1 - Search by id        *\n");
	printf("* 2 - Search by name      *\n");
	printf("* 3 - Search by phone     *\n");
	printf("* 0 - Return to main menu *\n");
	printf("***************************\n");
	printf("Entry: ");
	scanf("%d", &option);
	switch(option){
		case 1:
			printf("\nInsert the id: ");
			scanf("%d", &option);
			for(i = 0; i < MAX; i++){
				if(i == option && contact[i].phone != 0){
					printf("\nId: %d", i);
					printf("\nName: %s", contact[i].name);
					printf("\nPhone: %d", contact[i].phone);
					printf("\nEmail: %s", contact[i].email);
					option = -1;
				}
			}
			if(option != -1){
				printf("\nContact not found! Returning to main menu...");
			}
			break;

		case 2:
			printf("\nInsert the name: ");
			scanf("%s", busca);
			for(i = 0; i < MAX; i++){
				if(!strcmp(contact[i].name,busca) && contact[i].phone != 0){
					printf("\nId: %d", i);
					printf("\nName: %s", contact[i].name);
					printf("\nPhone: %d", contact[i].phone);
					printf("\nEmail: %s", contact[i].email);
					option = -1;
				}
			}
			if(option != -1){
				printf("\nContact not found! Returning to main menu...");
			}
			break;

		case 3:
			printf("\nDO FUNCTION TO SEARCH BY PHONE");
			break;

		case 0:
			printf("\nReturning to main menu...");
			break;

		default:
			printf("\nInvalid Entry! Returning to main menu...");
			break;
	}
}

void option0(){
	int option;
	printf("\n");
	system("clear");
	printf("***********************\n");
	printf("* Exit the program... *\n");
	printf("* Sure?               *\n");
	printf("* 0 - Cancel          *\n");
	printf("* 1 - Quit            *\n");
	printf("***********************\n");
	printf("Entry: ");
	scanf("%d", &option);
	if(option){
		printf("\nSystem shutting down...\n\n");
		exit(0);
	}else{
		printf("\nReturning to main menu...");
	}
}

void mainMenu(TContact *contact){
	int option, i;
	printf("\n");
	system("clear");
	printf("**********************\n");
	printf("* 1 - Insert contact *\n");
	printf("* 2 - Delete contact *\n");
	printf("* 3 - Update contact *\n");
	printf("* 4 - Sort contacts  *\n");
	printf("* 5 - Show contacts  *\n");
	printf("* 6 - Search contact *\n");
	printf("* 0 - Exit           *\n");
	printf("**********************\n");
	printf("Entry: ");
	scanf("%d", &option);

	switch(option){
			case 1:
				option1(contact);				
				break;

			case 2:
				option2(contact);
				break;

			case 3:
				option3(contact);
				break;

			case 4:
				option4(contact);
				break;

			case 5:
				option5(contact);
				break;

			case 6:
				option6(contact);
				break;

			case 0:
				option0();
				break;

			default:
				printf("\nInvalid Entry!");
				printf("\nReturning to main menu...");
				break;
		}

}
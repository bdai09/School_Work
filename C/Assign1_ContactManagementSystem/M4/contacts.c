/* -------------------------------------------
Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Section:IPC144 - Assignment1_Milestone4
Date: Mar15, 2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* namePtr) {
	char ask;
	int done = 1;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", (*namePtr).firstName);
	//do while loop to get middle name if have one
	do {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's middle initial(s): ");
			scanf("%6s", (*namePtr).middleInitial);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);
	printf("Please enter the contact's last name: ");
	scanf("%35s", (*namePtr).lastName); 
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* addressPtr) {
	char ask;
	int done = 1;
	printf("Please enter the contact's street number: ");
	scanf("%u", &((*addressPtr).streetNumber));
	printf("Please enter the contact's street name: ");
	scanf("%40s", (*addressPtr).street);
	//do while loop to get appartment number if have
	do {
		printf("Do you want to enter an apartment number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's apartment number: ");
			scanf("%u", &((*addressPtr).apartmentNumber));
			done = 0;
		}
		else if (ask == 'n' || ask == 'Y')
			done = 0;
		else done = 1;
	} while (done == 1);
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", (*addressPtr).postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", (*addressPtr).city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

void getNumbers(struct Numbers* numbersPtr) {
	char ask;
	int done = 1;
	//do while loop to get cell number if have
	do {
		printf("Do you want to enter a cell phone number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's cell phone number: ");
			scanf("%20s", (*numbersPtr).cell);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);
	//do while loop to get home number if have
	do {
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's home phone number: ");
			scanf("%20s", (*numbersPtr).home);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);
	//do while loop to get business number if have
	do {
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's business phone number: ");
			scanf("%20s", (*numbersPtr).business);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);

}



















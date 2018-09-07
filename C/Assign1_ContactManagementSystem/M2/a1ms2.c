/* -------------------------------------------
Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Section:IPC144 - Assignment1_Milestone2
Date: Mar8, 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

int main(void)
{
	// Declare variables here and set flag
	struct Name name = { "", "", "" };
	struct Address address = { 0, "", 0, "" };
	struct Number numbers = { "", "", "" };
	char ask;
	int done = 1;
	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", name.firstName);
	//do while loop to get middle name if have one
	do {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's middle initial(s): ");
			scanf("%6s", name.middleInitial);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);
	printf("Please enter the contact's last name: ");
	scanf("%35s", name.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%u", &address.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%40s", address.street);
	//do while loop to get appartment number if have
	do {
		printf("Do you want to enter an apartment number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's apartment number: ");
			scanf("%u", &address.apartmentNumber);
			done = 0;
		}
		else if (ask == 'n' || ask == 'Y')
			done = 0;
		else done = 1;
	} while (done == 1);
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address.postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", address.city);

	// Contact Numbers Input:
	//do while loop to get cell number if have
	do {
		printf("Do you want to enter a cell phone number? (y or n): ");
		scanf(" %c", &ask);
		if (ask == 'y' || ask == 'Y') {
			printf("Please enter the contact's cell phone number: ");
			scanf("%20s", numbers.cell);
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
			scanf("%20s", numbers.home);
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
			scanf("%20s", numbers.business);
			done = 0;
		}
		else if (ask == 'n' || ask == 'N')
			done = 0;
		else done = 1;
	} while (done == 1);

	// Display Contact Summary Details
	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", name.firstName);
	printf("Middle initial(s): %s\n", name.middleInitial);
	printf("Last name: %s\n\n", name.lastName);
	printf("Address Details\n");
	printf("Street number: %u\n", address.streetNumber);
	printf("Street name: %s\n", address.street);
	printf("Apartment: %u\n", address.apartmentNumber);
	printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n\n", address.city);
	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", numbers.cell);
	printf("Home phone number: %s\n", numbers.home);
	printf("Business phone number: %s\n", numbers.business);

	// Display Completion Message
	printf("\nStructure test for Name, Address, and Numbers Done!\n");
	//return control to the operating system
	return 0;
}

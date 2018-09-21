/* -------------------------------------------
Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Section:IPC144 - Assignment2_Milestone4
Date: April 5, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"

#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* namePtr) {
	int askname;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", (*namePtr).firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	askname = yes();  //yes function to check
	if (askname == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", (*namePtr).middleInitial);
	}
	else {
		*namePtr->middleInitial = '\0';
	}
	clearKeyboard();
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", (*namePtr).lastName);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address* addressPtr) {
	int askadd;
	printf("Please enter the contact's street number: ");
	(*addressPtr).streetNumber = getInt();   //getInt function to get integer
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", (*addressPtr).street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	askadd = yes();   //yes function to check
	if (askadd == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%u", &((*addressPtr).apartmentNumber));
	}
	else {
		(*addressPtr).apartmentNumber = '\0';
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", (*addressPtr).postalCode);
	clearKeyboard(); 
	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", (*addressPtr).city);
}

// getNumbers:
void getNumbers(struct Numbers* numbersPtr) {
	int askhp, askbp;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbersPtr->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
	askhp = yes();   //yes function to check optional input
	if (askhp == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbersPtr->home);
	}
	else {
		*numbersPtr->home = '\0';
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	askbp = yes();
	if (askbp == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbersPtr->business);
	}
	else {
		*numbersPtr->business = '\0';
	}
}
// getContact:
void getContact(struct Contact *contactPtr) {
	getName(&contactPtr->name);  // call getName function, getAddress and get Numbers
	getAddress(&contactPtr->address);
	getNumbers(&contactPtr->numbers);
}
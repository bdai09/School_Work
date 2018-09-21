/* -------------------------------------------
Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Section:IPC144 - Assignment2_Milestone2
Date: Mar22, 2018
----------------------------------------------
Assignment: 2
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


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* namePtr) {
	int askname;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", (*namePtr).firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	askname = yes();  //yes function to check
	if (askname == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", (*namePtr).middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%35s", (*namePtr).lastName);
}


// getAddress:
void getAddress(struct Address* addressPtr) {
	int askadd;
	printf("Please enter the contact's street number: ");
	(*addressPtr).streetNumber=getInt();   //getInt function to get integer
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", (*addressPtr).street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	askadd = yes();   //yes function to check
	if (askadd == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%u", &((*addressPtr).apartmentNumber));
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", (*addressPtr).postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", (*addressPtr).city);
}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* numbersPtr) {
	int askhp, askbp;
	printf("Please enter the contact's cell phone number: ");
	scanf("%s", (*numbersPtr).cell);
	clearKeyboard();
	printf("Do you want to enter a home phone number? (y or n): ");
	askhp = yes();   //yes function to check optional input
	if (askhp == 1) {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", (*numbersPtr).home);
		clearKeyboard();
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	askbp = yes();
	if (askbp == 1) {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", (*numbersPtr).business);
		clearKeyboard();
	}
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+ 

// getContact
void getContact(struct Contact *contactPtr) {
	getName(&contactPtr-> name);  // call getName function, getAddress and get Numbers
	getAddress(&contactPtr-> address);
	getNumbers(&contactPtr-> numbers);
}
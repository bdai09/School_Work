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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
	int done = 1;
	do {
		printf("(Press Enter to Continue)");
		clearKeyboard();
		done = 0;
	} while (done == 1);
}

// getInt: Empty function definition goes here:
int getInt(void) {
	char NL = 'x';
	int Value = 0;
	do {     //loop to check integer
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');
	return Value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int par1, int par2) {
	int validint;
	int done = 1;
	do {     //loop to continue ask input until get integer in range
		validint = getInt(); //check integer
		if (validint > par2 || validint < par1) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", par1, par2);
		}
		else done = 0;
	} while (done == 1);
	return validint;
}

// yes: Empty function definition goes here:
int yes(void) {
	char singlechar = 'x';
	char nl = 'x';
	int valid = 1;
	int result;
	do {      //loop to check all input
		scanf("%c%c", &singlechar, &nl);
		if (nl != '\n') {     //check if nl is enter
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (nl == '\n') {    //return value for Y, y, N, n
			if (singlechar == 'Y' || singlechar == 'y') {
				valid = 0;
				result = 1;
			}
			if (singlechar == 'N' || singlechar == 'n') {
				valid = 0;
				result = 0;
			}
		}
		else clearKeyboard();
	} while (valid == 1);
	return result;
}

// menu: Empty function definition goes here:
int menu(void) {
	int menuno;
	printf("Contact Management System\n");  //display menu
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	menuno = getIntInRange(0, 6);  //get selection when it is inside range 0-6
	printf("\n");
	return menuno;
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	int option;
	int check;
	int done = 1;
	struct Contact initialarray[MAXCONTACTS]= { //initialize value of structure
	{ { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	{{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};
	while (done == 1) {
		do {
			option = menu();  //display menu, select option
			switch (option) {   //check selection
			case 1:
				displayContacts(initialarray, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 2:
				addContact(initialarray, MAXCONTACTS);
                pause();
				printf("\n");
				break;
			case 3:
				updateContact(initialarray, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 4:
				deleteContact(initialarray, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 5:
				searchContacts(initialarray, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 6:
				sortContacts(initialarray, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			}
		} while (option != 0);   //loop until select 0 to exit
		printf("Exit the program? (Y)es/(N)o: "); //exit is selected
		check = yes();
		printf("\n");
		if (check == 1) {   //check if terminate
			printf("Contact Management System: terminated\n");
			done = 0;
		}
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {  //whileloop to read data
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {  //for loop to find if there is same numbers in structure
		if (strcmp(contacts[i].numbers.cell, cellNum)==0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int contfoo) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", contfoo);
}

// displayContact:
void displayContact(const struct Contact * contactPtr) {
		if (strlen(contactPtr->name.middleInitial) == 0) {  //print names if doesn't have middlename
			printf(" %s %s\n", contactPtr->name.firstName, contactPtr->name.lastName);
		}
		else {
			printf(" %s %s %s\n", contactPtr->name.firstName,
				contactPtr->name.middleInitial, contactPtr->name.lastName);
		}	   
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contactPtr->numbers.cell,
			contactPtr->numbers.home, contactPtr->numbers.business);
		if (contactPtr->address.apartmentNumber == 0 ) {  //print withouth apartment number
			printf("       %d %s, %s, %s\n", contactPtr->address.streetNumber,
				contactPtr->address.street, contactPtr->address.city, contactPtr->address.postalCode);
		}
		else {  //print all numbers if have apartmentNumber
			printf("       %d %s, Apt# %d, %s, %s\n", contactPtr->address.streetNumber,
				contactPtr->address.street, contactPtr->address.apartmentNumber,
				contactPtr->address.city, contactPtr->address.postalCode);
		}
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int consize) {   
	int i;
	int valid = 0;
	displayContactHeader();
	for (i = 0; i < consize; i++) { //for loop to display all contacts by checking if cellnumber exists
		if (strlen(contacts[i].numbers.cell) != 0) {
			displayContact(&(contacts[i]));
			valid++;
		}
	}
	displayContactFooter(valid);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int searchsize) {
	char tellNum[11] = "";
	int findnum;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(tellNum);  //call getTenDigitPhone function to get valide numbers
	printf("\n");
	findnum=findContactIndex(contacts, searchsize, tellNum);  //call function and use cell numbers to search contact
	if (findnum != -1) {
		displayContact(&(contacts[findnum])); //display the specific contact once found
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int Arraysize) {
	int i;
	for (i = 0; i < Arraysize; i++) {
		if (strlen(contacts[i].numbers.cell) == 0) {
			getContact(&(contacts[i]));   //add contact if cellnumber is empty
			printf("--- New contact added! ---\n");
			return;
		}
	}
	printf("*** ERROR: The contact list is full! ***\n");
}

// updateContact:
void updateContact(struct Contact contacts[], int updatesize) {
	char updateNum[11] = "";
	int find, askname, askadd, asknum;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(updateNum);
	find=findContactIndex(contacts, updatesize, updateNum); //use cell number to search contact
	if (find == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&(contacts[find])); //display contact 
		printf("\n");
		printf("Do you want to update the name? (y or n): "); //update contact if yes
		askname=yes();
		if (askname == 1) {
            getName(&(contacts[find].name));
        }
		printf("Do you want to update the address? (y or n): ");
		askadd = yes();
		if (askadd == 1) {
			getAddress(&(contacts[find].address));	
			clearKeyboard();	
		}
		printf("Do you want to update the numbers? (y or n): ");
		asknum = yes();
		if (asknum == 1) {
            getNumbers(&(contacts[find].numbers));
        }
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int sizedel) {
	char delNum[11] = "";
	int delfind, askdel; 
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(delNum);
	delfind = findContactIndex(contacts, sizedel, delNum); //locate contact by cellnumber
	if (delfind == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&(contacts[delfind]));//if find contact display it
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): "); //confirmation of deletion
		askdel = yes();
		if (askdel == 1) {
			contacts[delfind].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}

}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
	int i, j;
	struct Contact temp;
	for (i = size - 1; i > 0; i--) { //nested for loop to sort contacts
		for (j=0; j<i; j++) { //strcmp function to compare cellnumber
			if (strcmp(contacts[j].numbers.cell, contacts[j+1].numbers.cell) > 0) {  

				temp = contacts[j];  //switch contacts
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
		
	}
	printf("--- Contacts sorted! ---\n");
}


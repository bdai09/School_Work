/* -------------------------------------------
Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Section:IPC144 - Assignment2_Milestone2
Date: Mar25, 2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
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
	int Value=0;
	do {     //loop to check integer
	     scanf("%d%c", &Value,&NL);
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
		else done=0;
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
	} while (valid ==1);
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
	menuno=getIntInRange(0, 6);  //get selection when it is inside range 0-6
	return menuno;
}

// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void) {
	int option;
	int check;
	int done = 1;
	while (done == 1) {
		do {
			option = menu();  //display menu, select option
			switch (option) {   //check selection
			case 1:
				printf("\n<<< Feature 1 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 2:
				printf("\n<<< Feature 2 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 3:
				printf("\n<<< Feature 3 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 4:
				printf("\n<<< Feature 4 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 5:
				printf("\n<<< Feature 5 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			case 6:
				printf("\n<<< Feature 6 is unavailable >>>\n\n");
				pause();
				printf("\n");
				break;
			}			
		} while (option != 0);   //loop until select 0 to exit
		printf("\nExit the program? (Y)es/(N)o: "); //exit is selected
		check = yes();
		printf("\n");
		if (check == 1) {   //check if terminate
			printf("Contact Management System: terminated\n");
			done = 0;
		}
	}
}

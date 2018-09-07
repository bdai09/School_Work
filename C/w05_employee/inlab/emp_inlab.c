/*
Name: Bo Dai
Student number: 132954173
Email: bdai9@myseneca.ca
Workshop: Workshop5 Structures
Section: IPC144 - IN_LAB
Date: Feb 22, 2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2		

// Declare Struct Employee 
struct Employee
{
	int id;
	int age;
	double salary;
};

/* main program */
int main(void) {
	//define and initialize variables
	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");
	int i = 0;
	int NuE = 0;
	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			//for loop to display emp arrays data
			for (i = 0; i < SIZE && emp[i].id >0; i++) {
				printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");
			//check if emp array is full and adding new employee data
			if (NuE < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[NuE].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[NuE].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[NuE].salary);
				printf("\n");
				NuE++;
			}
			else { //output error if reach maximum size
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;
		default: 
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0; //return control to operating system
}


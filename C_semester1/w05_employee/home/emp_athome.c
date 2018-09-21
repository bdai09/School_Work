/*
Name: Bo Dai
Student number: 132954173
Email: bdai9@myseneca.ca
Workshop: Workshop5 Structures
Section: IPC144 - AT_HOME
Date: Feb 22, 2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4		

// Declare Struct Employee 
struct Employee
{
	int id;
	int age;
	double salary;
};

/* main program */
int main(void) 
{
	//define and initialize variables
	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");
	int i = 0;
	int NuE = 0;
	int target = 0;
	int flag = 0;
	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			//for loop to display emp arrays data
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id >0)
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
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
			else { 
				//output error if reach maximum size
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;

		case 3: // Update Employee Salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			flag = 0;
			//do while loop to find salary in the same index as input id
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &target);
				i = 0;
				while (i < SIZE && flag == 0) {
					emp[i].id == target ? flag = 1 : i++;
				}
			} while (flag == 0);
			//update and replace new salary
			printf("The current salary is %.2lf\n", emp[i].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[i].salary);
			printf("\n");
			break;

		case 4: // Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");
			flag = 0;
			//do while loop to find salary in the same index as input id
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &target);
				i = 0;
				while (i < SIZE && flag == 0) {
					emp[i].id == target ? flag = 1 : i++;
				}
			} while (flag == 0);
			//remove output for the employee id 
			printf("Employee %d will be removed\n", emp[i].id);
			printf("\n");
			emp[i].id = 0;
			NuE--;
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	//return control to operating system
	return 0; 
	
}







// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   99999.99
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/


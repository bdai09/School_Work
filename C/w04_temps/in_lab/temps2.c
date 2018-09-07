//-------------------------------------------------- 
// Name: Bo Dai
// Student Number:132954173
// Email: bdai9@myseneca.ca
// Section: IPC144 - IN_LAB 
// Workshop: Workshop4 Arrays

//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

// information about the printf, scanf identifier 
#include <stdio.h>

//the starting point of the program
int main(void)
{
	//define variables, and initializ arrays	
	int i = 0;
	int NUMS;
	float day_high[10];
	float day_low[10];

	//output title, request user to input days, and assign input value to NUMS
	printf("---=== IPC Temperature Calculator V2.0 ===---");
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUMS);
	
	//loop to test if imput value meet requirements
	while (NUMS > 10 || NUMS < 3) {
		printf("\nInvalid entry, please enter a number ");
		printf("between 3 and 10, inclusive: ");
		scanf("%d", &NUMS);
	}
	printf("\n");

	//use a for loop to assign data to arrays
	for (i = 0; i < NUMS; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%f", &day_high[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%f", &day_low[i]);
	}

	//after all input loop end, for loop to output parallel arrays as day, high, low
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < NUMS; i++)
		printf("%d    %.f    %.f\n", i + 1, day_high[i], day_low[i]);


	//return control to the operating system
	return 0;
}

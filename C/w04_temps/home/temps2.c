//-------------------------------------------------- 
// Name: Bo Dai
// Student Number:132954173
// Email: bdai9@myseneca.ca
// Section: IPC144 - AT_HOME 
// Workshop: Workshop4 Arrays

//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// information about the printf, scanf identifier 
#include <stdio.h>

//the starting point of the program
int main(void)
{
	//define variables, and initializ arrays	
	int NUMS, Day_H, Day_L, NAVE;
	float highest, lowest, Total, Aver;
	int i = 0;
	float day_high[10];
	float day_low[10];
	highest = 0.00;
	lowest = 0.00;
	Day_H = 0;
	Day_L = 0;
	NAVE = 0;
	Total = 0.00;
	//output title, request user to input days, and assign input value to NUMS
	printf("---=== IPC Temperature Calculator V2.0 ===---");
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUMS);

	//loop to test if input value meet requirements
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
		//conditional expressions, compare and get highest/lowest temperature and date
		highest <= day_high[i] ? (highest = day_high[i], Day_H = i + 1) : (highest = highest, Day_H = Day_H);
		lowest >= day_low[i] ? (lowest = day_low[i], Day_L = i + 1) : (lowest = lowest, Day_L = Day_L);
	}

	//after all input loop end, for loop to output parallel arrays as day, high, low
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < NUMS; i++)
		printf("%d    %.f    %.f\n", i + 1, day_high[i], day_low[i]);

	printf("\nThe highest temperature was %.f, on day %d\n", highest, Day_H);
	printf("The lowest temperature was %.f, on day %d\n", lowest, Day_L);

    //while loop to test input number for average days
	while (NAVE >= 0) {
		printf("\nEnter a number between 1 and %d to see ", NUMS);
		printf("the average temperature for the entered number of ");
		printf("days, enter a negative number to exit: ");
		scanf("%d", &NAVE);
		while ((NAVE < 1 || NAVE > 4) && NAVE >= 0) {
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &NAVE);
		}
		//for loop to calculate total temperature based on input days
		for (i = 0; i < NAVE; i++)
			Total = Total + day_high[i] + day_low[i];
		//calculate average temperature and output
		Aver = Total / ((float)(NAVE * 2));
		if (NAVE > 0)
			printf("\nThe average temperature up to day %d is: %.2f\n", NAVE, Aver);
		Total = 0.00;
	}
	printf("\nGoodbye!\n");
	//return control to the operating system
	return 0;
}

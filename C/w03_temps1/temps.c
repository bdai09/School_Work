// Name: Bo Dai
// Student Number:132954173
// Email: bdai9@myseneca.ca
// Section: IPC144 - AT_HOME 
// Workshop: Workshop3 Logic


#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 4
#include <stdio.h>

//the starting point of the program
int main(void)
{
	//define variables	
	int i, Day_H, Day_L;
	float High, Low, total_high, total_low, highest, lowest;
	//define a flag done, accumulator total_high, total_low, and assign initial values
	int done = 0;
	total_high = 0.00;
	total_low = 0.00;
	highest = -40.00;
	lowest = 40.00;
	Day_H = 0;
	Day_L = 0;
	//output the title of the application
	printf("---=== IPC Temperature Analyzer ===---");

	//set up "for" loop for temp input
	for (i = 0; i < NUMS; i++) {
		done = 0;
		//nested while loop to analyze the results, and use flag to jump out of the loop
		while (done == 0) {

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%f", &High);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%f", &Low);

			if (Low >= High || Low < -40 || Low > 40 || High < -40 || High >40) {
				printf("\nIncorrect values, temperatures must be in the ");
				printf("range -40 to 40, high must be greater than low.\n");
			}
			else {
				//if input is right, change flag, and accumulate temperature
				done = 1;
				total_high += High;
				total_low += Low;

				//conditional expressions, compare and get highest/lowest temperature and date
				highest <= High ? (highest = High, Day_H = i + 1) : (highest = highest, Day_H = Day_H);
				lowest >= Low ? (lowest = Low, Day_L = i + 1) : (lowest = lowest, Day_L = Day_L);
			}
		}
	}
	//after all loop end, output mean temperature, highest and lowest temperature value and date
	printf("\nThe average (mean) temperature was: %.2f\n", (total_high + total_low) / (float)NUMS / 2);
	printf("The highest temperature was %.f, on day %d\n", highest, Day_H);
	printf("The lowest temperature was %.f, on day %d\n", lowest, Day_L);

	//return control to the operating system
	return 0;
}

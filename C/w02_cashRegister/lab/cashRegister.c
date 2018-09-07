/* Student number:132954173
Seneca email: BDAI9@myseneca.ca
Name:Bo Dai
Workshop2: Computations- IN_LAB, Feb 1, 2018
cashRegister.c          */

#include <stdio.h>               // information about the printf identifier 
int main(void)                   //the starting point of the program
{
	int loonies, quarters;       //define varible loonies and quarters as integer, cash and balance as double
	double cash, remains, balance;    

	printf("Please enter the amount to be paid: $");  //start the program by asking the user to enter the amount
	scanf("%lf", &cash);               //user input amount and put in address cash
	loonies = cash;                      // integral loonies from cash amount
	remains = cash - loonies;
	quarters = remains / 0.25;           //calculate quarters number
	balance = cash - loonies - quarters*0.25;   //calculate balance remained
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies,remains);     //send output to the screen
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters,balance);
	return 0;                    //return control to the operating system
}

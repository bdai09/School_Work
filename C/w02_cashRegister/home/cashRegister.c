/*
    Name:      <Bo Dai>
    Section:   <IPC144-Workshop2: Computations-AT_HOME>
    Feb1, 2018  File name:cashRegister.c
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications


#include <stdio.h>               // information about the printf and scanf identifier 
int main(void)                   //the starting point of the program
{
	int loonies, quarters, dimes, nickels, pennies, balance2, balance3, balance4, balance5;       //define varibles type and assign constant varables value
	double cash, GST, totaldue, balance1;
	const double quarter = 0.25; 
	const double dime = 0.10; 
	const double nickel = 0.05; 
	const double penny = 0.01;

	printf("Please enter the amount to be paid: $");            //start the program by asking the user to enter the amount
	scanf("%lf", &cash);                                        //user input amount and put in address cash
	
	GST = 0.13*cash + 0.005;                                    //calculate and output GST
	printf("GST: %.2lf\n", GST);

	totaldue = GST+cash;                                        //calculate and output balance owing
	printf("Balance owing: $%.2lf\n", totaldue);

	loonies = totaldue;                                    // calculate loonies and balance 
	balance1 = totaldue-loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance1);     //send loonies and balance output to the screen

	quarters = balance1/quarter;                  //calculate quarters, integer division and modulus to get remains
	balance2 = ((int)(balance1*100)) %((int)(100*quarter));     
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)balance2/100);     //send quarters and balance output to the screen

	
	dimes = balance2/((int)(100*dime));                        //calculate dimes, integer division and modulus for remains
	balance3 = balance2 %((int)(dime*100));
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)balance3/100);           //send dimes and balance output to the screen

	nickels = balance3/((int)(100*nickel));                    //calculate nickels and output balance
	balance4 = balance3 %((int)(nickel*100));
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)balance4/100);

	pennies = balance4/((int)(100*penny));                     //calculate pennies and output balance
	balance5 = balance4 %((int)(100*penny));
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)balance5/100);

	return 0;                                                  //return control to the operating system
}

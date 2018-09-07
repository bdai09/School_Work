// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////

#include "SavingsAccount.h" 
#include "ChequingAccount.h"
namespace sict {

	// define interest rate
	const double interest = 0.05;
	const double tran_fee = 0.50;
	const double monthfee = 2.00;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* ptr, double initial) {
		iAccount* typeptr = nullptr;
		if (ptr[0]=='S') {
			typeptr = new SavingsAccount(initial, interest);
		}
		else if (ptr[0] == 'C') {
			typeptr = new ChequingAccount(initial, tran_fee, monthfee);
		}
		return typeptr;
	}
}

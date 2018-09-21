// OOP244 Workshop 8: Virtual Functions
// File: Allocator.cpp
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////

#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	const double interest = 0.05;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* ptr, double initial) {
		iAccount* typeptr = nullptr;
		if (ptr[0]=='S') {
			typeptr = new SavingsAccount(initial, interest);
		}
		return typeptr;
	}








}

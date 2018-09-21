// OOP244 Workshop 8: Virtual Functions 
// File: iAccount.h
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {
	public:
                virtual ~iAccount() {}
		// TODO: credit adds +ve amount to the balance
		virtual bool credit(double)=0;

		// TODO: debit subtracts a +ve amount from the balance
		virtual bool debit(double) = 0;

		// TODO: month end adds month end costs
		virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
		virtual void display(std::ostream&) const = 0;
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);
}
#endif


// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
// Description:
// This file defines the iAccount interface
///////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account:public iAccount{
		double _balance;

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};


}
#endif

// OOP244 Workshop 8: Virtual Functions
// File: Account.cpp
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////


#include "Account.h"

namespace sict {
	//return current balance of the account
	double Account::balance() const {
		return _balance;
	}
	//constructor initializes account balance, defaults to 0.0 
	Account::Account(double src) {
		if (src > 0) {
			_balance = src;
		}
		else { _balance = 0.0; }
	}

	//credit adds +ve amount to the balance 
	bool Account::credit(double amount) {
		bool result;
		if (amount > 0) {
			_balance += amount;
			result = true;
		}
		else { result = false; }
		return result;
	}

	//debit subtracts a +ve amount from the balance
	bool Account::debit(double amount) {
		bool result;
		if (amount > 0) {
			_balance -= amount;
			result = true;
		}
		else { result = false; }
		return result;
	}
}

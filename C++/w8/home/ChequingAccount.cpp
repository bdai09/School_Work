// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double trans, double monthfee) :Account::Account(balance) {
		if (trans > 0) {
			transfee = trans;
		}
		else { transfee = 0.0; }
		if (monthfee > 0) {
			endfee = monthfee;
		}
		else { endfee = 0.0; }
	}

	

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double deposit) {
		bool result=false;
		if (Account::credit(deposit)) {
			Account::debit(transfee);
			result = true;
		}
		return result;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	
	bool ChequingAccount::debit(double src) {
		bool result = false;
		if (Account::debit(src)) {
			Account::debit(transfee);
			result = true;
		}
		return result;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		debit(endfee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& ost) const {
		ost << "Account type: Chequing" << std::endl;
		ost.setf(ost.fixed, ost.floatfield);
		ost.precision(2);
		ost << "Balance: $" << balance() << std::endl;
		ost << "Per Transaction Fee: " << transfee<< std::endl;
		ost << "Monthly Fee: " << endfee << std::endl;
	}
}
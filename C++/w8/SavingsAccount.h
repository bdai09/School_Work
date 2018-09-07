// OOP244 Workshop 8: Virtual Functions
// File: SavingsAccount.h
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount: public Account{ 
		double savingrate;
	
	public:
		    // TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// TODO: perform month end transactions
			void monthEnd();

			// TODO: display inserts the account information into an ostream			
			void display(std::ostream&) const;
	};
}
#endif

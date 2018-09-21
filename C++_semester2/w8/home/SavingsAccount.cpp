// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173)
///////////////////////////////////////////////////
#include <iomanip>
#include "SavingsAccount.h"
namespace sict {
	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double bal, double rate):Account::Account(bal) {
		if (rate > 0) {
			savingrate = rate;
		}
		else { savingrate = 0.0; }
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd() {
		credit(balance()*savingrate);
	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& ost) const {
		ost << "Account type: Savings" << std::endl;
		ost.setf(ost.fixed, ost.floatfield);
		ost.precision(2);
		ost << "Balance: $"  << balance() << std::endl;
		ost << "Interest Rate (%): " << savingrate*100 << std::endl;
	}
}
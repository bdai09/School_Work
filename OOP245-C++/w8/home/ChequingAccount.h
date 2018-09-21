// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: 2.0
// Name			Date
// Bo Dai        2018/07/12
//Student number : 132954173
///////////////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount: public Account  {
		double transfee;
		double endfee;

		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif


/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.1
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Bo Dai        2018/05/31            allow longer names
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/



//include the necessary headers
#include<iostream>
#include<cstring>
#include"CRA_Account.h"
using namespace std;

// the sict namespace
namespace sict {
	// definition for set(...) 
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		if (sin<max_sin && sin>min_sin) {
			strncpy(Fam_Name, familyName, max_name_length);
			strncpy(Given_Name, givenName, max_name_length);
			SIN = sin;
		}
		else {
			SIN = 0; //ignore the client's data, set an empty state
		}
	}
	
	// definition for isEmpty(...) 
	bool CRA_Account::isEmpty() const {
		bool valid = true;
		if (SIN != 0) {
			valid = false;
		}
		return valid;
	}
	// definition for display(...) 
	void CRA_Account::display() const {
		if (SIN != 0) { //if object not empty display
			cout << "Family Name: " << Fam_Name << endl;
			cout << "Given Name : " << Given_Name << endl;
			cout << "CRA Account: " << SIN << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}

	}
}
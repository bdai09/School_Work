/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
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
#include <iomanip>
using namespace std;

// the sict namespace
namespace sict {
	// definition for set(...) 
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		int Sinn = sin;
		int sum = 0;
		//loop to calculate sum 
		for (int i = 0; i <= 4; i++) {
			int newnum = Sinn % 100;
			int sumeven = newnum / 10 * 2;
			sum = sum + newnum % 10 + sumeven / 10 + sumeven % 10;
			Sinn = Sinn / 100;
		}
		int test = sum % 10;
		//test if sin number is valid,and if familyName and givenName valid, if valid copy it
		if (sin<max_sin && sin>min_sin && test==0 &&familyName[0]!='\0' && givenName[0]!='\0') {
			strncpy(Fam_Name, familyName, max_name_length);
			strncpy(Given_Name, givenName, max_name_length);
			SIN = sin;
			numofyear = 0;
		}
		else {
			SIN = 0; //ignore the client's data if not valid, set an empty state
		}	
	}	
	// definition for isEmpty(...) 
	bool CRA_Account::isEmpty() const {
		bool valid = true;
		if (SIN != 0) { //if sin number is valid, then is not Empty
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
			cout << fixed << setprecision(2); //set up precision
			for (int t = 0; t < numofyear; t++) { //output according to range
				if (owedbal[t] > 2.00) {
					cout << "Year (" << retyear[t] << ") balance owing: " << owedbal[t] << endl;
				}
				else if (owedbal[t]<-2.00) {
					cout << "Year (" << retyear[t] << ") refund due: " << -owedbal[t] << endl;
				}
				else {
					cout << "Year (" << retyear[t] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else { //if object empty 
			cout << "Account object is empty!" << endl;
		}
	}
	//definition for set(...) 
	void CRA_Account::set(int year, double balance) {
		if (SIN != 0 && numofyear < max_yrs) { //if sin valid and has room
			retyear[numofyear] = year;  //store data and accumulate year
			owedbal[numofyear] = balance;
			numofyear++;
		}
	}
}
#pragma once
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
// header safeguards
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

// sict namespace
namespace sict {
	//maximum number of char for account holder name
	int const max_name_length = 40;
	//smallest SIN
	int const min_sin = 100000000;
	//largest SIN
	int const max_sin = 999999999;
	//define the CRA_Account class
	class CRA_Account {
		char Fam_Name[max_name_length + 1];
		char Given_Name[max_name_length + 1];
		int SIN;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};

}
#endif
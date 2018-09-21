/**********************************************************
// Workshop 1: From One Translation Unit to Another
// CString.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/
#include<cstring>
#include "CString.h"

int STORED=3;
namespace w1 {
	//Constructor
	CString::CString(const char* addstr):MAX(STORED) {
		if (addstr == nullptr) {
			cstring = new char[1];
			cstring[0]='\0';
		}
		else {
			cstring = new char[MAX + 1];
			strncpy(cstring, addstr, MAX);
			cstring[MAX] = '\0';
		}
	}
	//destructor
	CString::~CString() {
		delete[] cstring;
	}

	void CString::display(std::ostream& os) const{
			os << cstring;
	}
	//helper
	std::ostream& operator<<(std::ostream& ost, const CString& srcstr) {
		static int cnt = 0;
		ost << cnt++ << ": ";
		srcstr.display(ost);
		return ost;
	}
}
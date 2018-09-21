/**********************************************************
// Workshop 1: From One Translation Unit to Another
// CString.h
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
//safe guards against repeating
#ifndef W1_CSTRING_H 
#define W1_CSTRING_H
#include<iostream>
namespace w1 {
	class CString {
		//Number of characters stored
		const int MAX;
		char* cstring;
	public: 
	
		CString(const char* addstr);
		void display(std::ostream&)const;
		~CString();
	};
	std::ostream& operator<<(std::ostream& ost, const CString& CString);
}
#endif
/**********************************************************
// Workshop 1: From One Translation Unit to Another
// process.cpp
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
#include"process.h"

	void process(char*string, std::ostream& ost) {
		w1::CString temp(string);
		ost << temp <<std::endl;
	}

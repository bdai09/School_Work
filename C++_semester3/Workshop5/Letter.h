/**********************************************************
// Workshop 5: Lambda Expressions
// Letter.h
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Oct 10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_LETTER_H
#define SICT_LETTER_H


namespace sict {
   enum class Letter {A1, A, B1 , B, C1 , C, D1 , D, F,X };
   std::string strscore = "";
   template<typename T>
   const char* convert(const T& letter) {

	   switch (letter) {
	          case Letter::A1:
		            strscore = "A+";
		            break;
	           case Letter::A:
		            strscore = "A";
		            break;
	           case Letter::B1:
		            strscore = "B+";
		            break;
	           case Letter::B:
		             strscore = "B";
		             break;
	           case Letter::C1:
		             strscore = "C+";
		             break;
	          case Letter::C:
		             strscore = "C";
		              break;
			  case Letter::D1:
				  strscore = "D+";
				  break;
	          case Letter::D:
		             strscore = "D";
		             break;
	          case Letter::F:
		             strscore = "F";
		             break;
	          default:
		             strscore = "";
		             break;
	   }
	   return strscore.c_str();
   }
}

#endif 
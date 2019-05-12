/**********************************************************
// Workshop 5: Lambda Expressions
// w5.cpp
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

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
    try{
		sict::Grades grades(argv[1]);
		auto letter = [](double grade) {
			if (grade >= 90)
				return Letter::A1;
			else if (90 > grade && grade >= 80)
				return Letter::A;
			else if (80 > grade && grade>= 75)
				return Letter::B1;
			else if (75 > grade && grade >= 70)
				return Letter::B;
			else if (70 > grade && grade >= 65)
				return Letter::C1;
			else if (65 > grade && grade >= 60)
				return Letter::C;
			else if (60 > grade && grade >= 55)
				return Letter::D1;
			else if (55 > grade && grade>= 50)
				return Letter::D;
			else if (50 > grade)
				return Letter::F;
			return Letter::X;
		};
		grades.displayGrades(std::cout, letter);
     }
	catch (int) {
		std::cerr << argv[0] << ": Cannot open file " << argv[1];
	}
	catch (...) {
		std::cerr << "Error!";
	}
	return 0;
}
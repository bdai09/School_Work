/**********************************************************
// Workshop 5: Lambda Expressions
// Grades.cpp
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
#include <string>
#include <fstream>
#include<iomanip>
#include "Grades.h"
#include <iostream>
using namespace std;

namespace sict {

	Grades::Grades() { //safe empty state
		students = nullptr;
		num = 0;
		stu_grade = nullptr;
	}
	//receive address of fille and store info
	Grades::Grades(const char* addr) {
		string temp;
		int count=0;
		ifstream fin(addr);
		if (fin.is_open()) {
			//std::cout << "openopen" << endl;
			while (!fin.eof()) {//count lines
				getline(fin, temp);
				count++;
			}
			num = count-1;
			students = new string[num];//allocate dynamic memory
			stu_grade = new double[num];
			fin.clear();
			fin.seekg(0);
			for (int i = 0;i < num;++i) { //store value
				getline(fin, temp);
				int sep = temp.find(' ');
				students[i] = temp.substr(0, sep);
				temp.erase(0, sep + 1);
				stu_grade[i] = stod(temp);
			}
			fin.close();
		}
		else { //empty state
			students = nullptr;
			stu_grade = nullptr;
			num = 0;
			throw num;
		}
	}
	//destructor
	Grades::~Grades() {
		delete[] students;
		delete[] stu_grade;
	}
}
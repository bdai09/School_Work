/**********************************************************
// Workshop 5: Lambda Expressions
// Grades.h
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

#ifndef SICT_GRADES_H
#define SICT_GRADES_H
#include<string>
namespace sict {
	
	class Grades {
		std::string* students;
		int num;
		double* stu_grade;
	public:
		Grades();
		Grades(const char*);//receive address of fille and store info
		template<typename F>
		void displayGrades(std::ostream& os, F addr) const {
			for (int i = 0;i < num;i++) {
                os.precision(2);
				os << "  " << students[i].c_str() << " " << std::fixed << stu_grade[i] << " ";
				os.width(4);
				os << std::left << convert(addr(stu_grade[i])) << std::endl;
			}
		}
		Grades(const Grades&) = delete; //prohibits copying, moving, assign
		Grades& operator=(const Grades&) = delete;
		Grades(Grades&&) = delete;
		Grades& operator=(Grades&&) = delete;
		~Grades();
	};
}

#endif 
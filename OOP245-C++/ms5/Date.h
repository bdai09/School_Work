// Final Project Milestone 1
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/07/05
//Student number : 132954173
// Description: The Date class encapsulates a date with format YYYY/MM/DD
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#define NO_ERROR 0 //No error-the date is valid
#define CIN_FAILED 1 //istream failed on information entry
#define YEAR_ERROR 2 //Year value is invalid
#define MON_ERROR 3//Month value is invalid
#define DAY_ERROR 4 //Day value is invalid

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
  //hold the expiry data of the perishable items
  class Date {
	  int year;
	  int month;
	  int day;
	  int compval;
	  int errorstate;
     int mdays(int, int)const;  //return number of days in month of year
	 void errCode(int errorCode); //set error state var to one of values listed
 
  public:
	  //no argument constructors,and three argument constructors
	  Date(); 
	  Date(int, int, int);
	  bool isEmpty() const;
	  //comparison operators
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  //queries and modifier
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
	  
  };
      //helper functions
      std::istream& operator>>(std::istream&, Date&);
	  std::ostream& operator<<(std::ostream&, const Date&);




}
#endif
// Final Project Milestone 1
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/07/05
//Student number : 132954173
// Description: The Date class encapsulates a date with format YYYY/MM/DD
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_

  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
  //set error state var to one of values listed
  void Date::errCode(int errorCode) {

	  errorstate = errorCode;
  }
  Date::Date() {
	  year = 0;//set safe empty state
	  month = 0;
	  day = 0;
	  errorstate = NO_ERROR;
	  compval = 0;
   }
  Date::Date(int year, int month, int day) {
	  bool yeartest = year <= max_year && year >= min_year;
	  bool monthtest = month <= 12 && month >= 1;
	  bool daytest = day <= mdays(month, year) && day >= 1;
	  //check range, if out of range stop validation
	  if (yeartest == 1) {
		  if (monthtest == 1) {
			  if (daytest == 1) {  //if all valid stores value
				  this->year = year;
				  this->month = month;
				  this->day = day;
				  compval = year * 372 + month * 13 + day;
				  errorstate = NO_ERROR;
			  }
			  else {
				  *this = Date();   //safe empty state
				  errorstate = DAY_ERROR;
			  }
		  }
		  else {
			  *this = Date();
			  errorstate = MON_ERROR;
		  }
	  }
	  else {
		  *this = Date();
		  errorstate = YEAR_ERROR;		  
	  }
  }
  bool Date::isEmpty() const {
	  bool valid = true;
	  //if current object has valid data, then object is not Empty
	  if (year != 0 || month != 0 || day != 0) {
		  valid = false;
	  }
	  return valid;
  }

  bool Date::operator==(const Date& rhs) const {
	  bool test = false;
	  //if both objects are not empty
	  if (!isEmpty() && !rhs.isEmpty() && compval==rhs.compval) {
		  test = true;
	  } 
	  return test;
  }
  bool Date::operator!=(const Date& rhs) const {
	  bool test = true;
	  if (*this==rhs) {
		  test = false;
	  }
	  return test;
  }
  bool Date::operator<(const Date& rhs) const {
	  bool test = false;
	  //if both objects are not empty
	  if (!isEmpty() && !rhs.isEmpty() && compval < rhs.compval) {
		  test = true;
	  }
	  return test;
  }
  bool Date::operator>(const Date& rhs) const {
	  bool test = false;
	  //if both objects are not empty
	  if (!isEmpty() && !rhs.isEmpty() && compval > rhs.compval) {
		  test = true;
	  }
	  return test;
  }
  bool Date::operator<=(const Date& rhs) const {
	  bool test = false;
	  //if both objects are not empty
	  if (!isEmpty() && !rhs.isEmpty() &&compval <= rhs.compval) {
		  test = true;
	  }
	  return test;
  }
  bool Date::operator>=(const Date& rhs) const {
	  bool test = false;
	  //if both objects are not empty
	  if (!isEmpty() && !rhs.isEmpty() && compval >= rhs.compval) {
		  test = true;
	  }
	  return test;
  }
  //Queries and modifier
  //errCode()return error state as error code value
  int Date::errCode() const {
	  return errorstate;
  }
  //return true if error state is not NO_ERROR
  bool Date::bad() const {
	  bool result = true;
	  if (errorstate == NO_ERROR) {
		  result = false;
	  }
	  return result;
  }
  //read date check format, and check valid
  std::istream& Date::read(std::istream& istr) {
	  char letter;
	  int num;
	  int temp_year = 0;
	  int temp_month = 0;
	  int temp_day=0;
	  int temp_erro = 0;
	  if (istr >> num && !istr.fail()) {
		  temp_year = num;
		  if (istr >> letter&& istr.fail()) {
			  temp_erro=CIN_FAILED;
		  }
		  else {
			  if (istr >> num && !istr.fail()) {
				  temp_month = num;
				  if (istr >> letter && istr.fail()) {
					  temp_erro=CIN_FAILED;
				  }
				  else {
					  if (istr >> num && !istr.fail()) {
						  temp_day = num;
					  } 
					  else{ temp_erro=CIN_FAILED; 
					  }
				  }
			  }
			  else{ temp_erro=CIN_FAILED; }
		  }
	  }else{
		  temp_erro=CIN_FAILED;
	  }
	  if (temp_erro == 0) {
		  Date temp(temp_year, temp_month, temp_day);
		  if (!temp.bad()) {
			  *this = temp;
		  }
		  else {
			  errCode(temp.errorstate);
		  }
	  }
	  else {
		  errCode(temp_erro);
	  }
	  return istr;
  }
  //write date in YYYY/MM/DD format
  std::ostream& Date::write(std::ostream& ostr) const {
	  ostr << year << '/'
		  << setw(2) << setfill('0') << month << '/'
		  << setw(2) << setfill('0') << day;
	  ostr.fill(' ');
	  return ostr;
  }
  //helper functions
  std::istream& operator>>(std::istream& istr, Date& des) {
	  return des.read(istr);
  }
  std::ostream& operator<<(std::ostream& ostr, const Date& src) {
	  return src.write(ostr);
  }
}

// Final Project Milestone 5
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/08/7
//Student number : 132954173
// Description: The Perishable class is a concrete class that
//encapsulates the information for perishable product
/////////////////////////////////////////////////////////////////
#include "Perishable.h"
#include <cstring>
#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>

namespace AMA {

	//no argument constructors
	Perishable::Perishable():Product('P') {
		 //set current object to safe empty state
		expire_date = Date();
	}

	//receive reference to an fstream object, an optional bool, 
	//returns reference to the fstream object
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		char seperate = ',';
		//insert data of current object seperated by comma
		file
			<< seperate << expire_date;
		if (newLine == true) { //if bool parameter true put newline
			file << std::endl;
		}
		return file;
	}

	//extract data fields for a single file record
	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file); //call base version	
	        //file.ignore();
		expire_date.read(file); //load expiry date
		return file;
	}

	//This query receives reference to ostream object,a bool 
	//returns a reference to the ostream object
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (Product::isClear()&& !Product::isEmpty()) {
			if (linear == true) { //if bool parameter true output following format
				os << std::setfill(' ');
				os << expire_date ;
			}
			else {  //if bool parameter false output following format
				os <<std::endl<< " Expiry date: " << expire_date ;
			}
		}
		return os;
	}

	//This modifier receives a reference to an istream object,
	//returns a reference to the istream object
	//extracts the data fields for the current object.
	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		Date Temp;
		if (Product::isClear()) { //is no error in extracting data
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> Temp;  //input date
			if (Temp.bad()) { //if date obj is in error state
				int option=Temp.errCode();
				switch (option) {
				case CIN_FAILED:
					Product::message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					Product::message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					Product::message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					Product::message("Invalid Day in Date Entry");
					break;
				default:
					break;
				}
			    is.setstate(std::ios::failbit);//set to failed state
			}
			if(!is.fail()) { //if not fail copy assign to current obj
				expire_date = Temp;
			}
		}
		return is;
	}

	//return expiry date for perishable product
	const Date& Perishable::expiry() const {
		return expire_date;
	}




}
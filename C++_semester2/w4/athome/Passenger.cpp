/**********************************************************
// Workshop 4: Constructors-AT_HOME
// Passenger.cpp
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/06/07
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/
// TODO: add file header comments here
// TODO: add your headers here
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Passenger.h"
using namespace std;

 // TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		strcpy(Name, "\0");//set empty state
		strcpy(Destination, "\0");
		yearofdep = 0;
		dayofdep = 0;
		monthofdep = 0;
	};
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* namepass, const char* namedes) {
		//if strings are not empty, copy data
		if (namepass != nullptr && namedes != nullptr && namepass[0] != '\0' && namedes[0] != '\0') {
			strncpy(this->Name, namepass, 31);
			strncpy(this->Destination, namedes, 31);
			this->Name[31] = '\0';
			this->Destination[31] = '\0';
			this->yearofdep = 2017;
			this->dayofdep = 1;
			this->monthofdep = 7;
		}
		else {
			//ignore the client's data if not valid, set an empty state
			/*strcpy(this->Name, "\0");
			strcpy(this->Destination, "\0");
			this->yearofdep = 0;
			this->dayofdep = 0;
			this->monthofdep = 0;*/
			*this = Passenger();
		}
	}
	// TODO: implement the constructor with 5 parameters here
	Passenger::Passenger(const char* namepass, const char* namedes, int year,int month, int day) {
		//if strings are not empty, copy data
		if (namepass != nullptr && namedes != nullptr && namepass[0] != '\0' 
			&& namedes[0] != '\0'&& (year < 2021 && year>2016) && 
			(month < 13 && month>0)&& (day < 32 && day>0)) {
			strncpy(this->Name, namepass, 31);
			strncpy(this->Destination, namedes, 31);
			this->Name[31] = '\0';
			this->Destination[31] = '\0';
			this->yearofdep = year;
			this->monthofdep = month;
			this->dayofdep = day;
		}
		else {
			//ignore the client's data if not valid, set an empty state
			strcpy(Name, "\0");
			strcpy(Destination, "\0");
			this->yearofdep = 0;
			this->monthofdep = 0;
			this->dayofdep = 0;
		}	
	}
	// TODO: implement isEmpty query here
	//isEmpty(...) tor report if Passenger object is empty
	bool Passenger::isEmpty() const {
		bool valid = true;
		//if Name and Destination is not empty, then object is not Empty
		if (Name[0] != '\0' || Destination[0] != '\0') {
			valid = false;
		}
		return valid;
	}
	// TODO: implement display query here
	//display(...) display contents of Passenger object
	void Passenger::display() const {
		if (!isEmpty()) { //if object not empty display
			cout << Name << " - " << Destination <<" on "
				<< yearofdep<<"/"
				<<setw(2)<<setfill('0')<<monthofdep<<"/"
				<<setw(2)<<setfill('0')<<dayofdep<< endl;
		}
		else { //if object empty 
			cout << "No passenger!" << endl;
		}
	}
	//name() return address of Name or address of empty string if empty
	const char* Passenger::name() const {
		return (!isEmpty() ? this->Name : "");
	}
	//canTravelWith(...) check if referenced object can travel with current object
	bool Passenger::canTravelWith(const Passenger& passobject) const {
		bool cantravel=true;
		if (strcmp(passobject.Destination, this->Destination)!=0 || passobject.dayofdep != this->dayofdep ||
			passobject.monthofdep != this->monthofdep || passobject.yearofdep != this->yearofdep) {
			cantravel = false;
		}
		return cantravel;
	}

}
/**********************************************************
// Workshop 4: Constructors
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
#include"Passenger.h"
using namespace std;

 // TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		strcpy(Name, "");
		strcpy(Destination, "");//empty state
	};
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* namepass, const char* namedes) {
		//if strings are not empty, copy data
		if (namepass != nullptr && namedes != nullptr && namepass[0] != '\0' && namedes[0] != '\0') {
			strncpy(Name, namepass, 31);
			strncpy(Destination, namedes, 31);
		}
		else {
			//ignore the client's data if not valid, set an empty state
			strcpy(Name, "");
			strcpy(Destination, "");
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
			cout << Name << " - " << Destination << endl;
		}
		else { //if object empty 
			cout << "No passenger!" << endl;
		}
	}
}
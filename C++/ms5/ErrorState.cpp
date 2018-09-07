// Final Project Milestone 2
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/07/10
//Student number : 132954173
// Description: The ErrorState class manages the error state of 
//client code and encapsulates the last error message.
/////////////////////////////////////////////////////////////////
#include "ErrorState.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace AMA {

	//no argument/one argument constructors
	ErrorState::ErrorState(const char* errorMessage) {
		addrmessage = nullptr;
		if (errorMessage == nullptr) {
			message('\0');
		}
		else {
			message(errorMessage);
		}
	}

	//deallocates memory that dynamically allocated by the current object
	ErrorState:: ~ErrorState() {
		delete[] addrmessage;
	}

	//clear message stored by current obj and set to empty state
	void ErrorState::clear() {
		message('\0');//safe empty state
	}

	//true if the current object is in a safe empty state
	bool ErrorState::isClear() const {
		return (addrmessage[0] == '\0');
	}

	//stores a copy of the string pointed to by str
	void ErrorState::message(const char* str) {
		if (str != nullptr) {
			if (addrmessage != nullptr) {
				addrmessage[0] = '\0';
				delete[] addrmessage;
				addrmessage = nullptr;
			}
			int count = strlen(str);
			addrmessage = new char[count + 1];
			strncpy(addrmessage, str, count);
			addrmessage[count] = '\0';
		}
		else {
			if (addrmessage != nullptr) {
				addrmessage[0] = '\0';
				delete[] addrmessage;
				addrmessage = nullptr;
			}
			addrmessage = new char[1];
			addrmessage[0] = '\0';
		}
	}

	//return address of message stored in current object
	const char* ErrorState::message()const {
		return addrmessage;
	}
	
	//helper functions
	std::ostream& operator<<(std::ostream& ostr, const ErrorState& src) {	
		if (!src.isClear()) {
			ostr << src.message();
		}
		return ostr;
	}
}

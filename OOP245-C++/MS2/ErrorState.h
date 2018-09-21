// Final Project Milestone 2
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/07/10
//Student number : 132954173
// Description: The ErrorState class manages the error state of 
//client code and encapsulates the last error message.
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace AMA {
	
	class ErrorState {
		//a pointer hold the address of the message
		char* addrmessage;
	public:
		//no argument/one argument constructors
		explicit ErrorState(const char* errorMessage = nullptr);

		//deleted copy constructor prevents copying of any ErrorState object
		ErrorState(const ErrorState& ) = delete;

		//deleted assignment operator prevents assignment of ErrorState object to current object.
		ErrorState& operator=(const ErrorState& ) = delete;

		//deallocates memory that dynamically allocated by the current object
		virtual ~ErrorState();

		//clear message stored by current obj and set to empty state
		void clear();

		//true if the current object is in a safe empty state
		bool isClear() const;

		//stores a copy of the string pointed to by str
		void message(const char* );

		//return address of message stored in current object
		const char* message()const;

	};
	//helper functions
	std::ostream& operator<<(std::ostream&, const ErrorState&);

}
#endif
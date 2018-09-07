/**********************************************************
// Workshop 4: Constructors-AT_HOME
// Passenger.h
///////////////////////////////////////////////////////////
// Name			Date		                        
// Bo Dai        2018/06/07          
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

	
// TODO: add file header comments here	
// TODO: add header file guard here,header safeguards
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
// TODO: declare your namespace here, sict namespace
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char Name[32];
		char Destination[32];
		int yearofdep;
		int monthofdep;
		int dayofdep;
	public: //member functions
		Passenger(); //default constructor
		Passenger(const char* , const char* );
		Passenger(const char*, const char*, int, int, int);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};
}
#endif
/**********************************************************
// Workshop 6: Class with a Resource-At_Home
// Contact.cpp
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/07/05
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: insert header files
#include<iostream>
#include <iomanip>
#include<cstring>
#include"Contact.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Contact::Contact() {
		name[0] = '\0';  //set empty state
		phoneptr=nullptr;
		np=0;   
	}
	// TODO: implement the two-argument constructor
	Contact::Contact(const char* newname, const long long* newptr, int newnp) {
		bool valid =(newname!=nullptr&& newname[0]!='\0' && newnp >= 0);
		if (valid) {
			//accept data
			strncpy(name, newname, 19);
			name[19] = '\0';
			if (newnp > 0) {		
				//check if valid phone
				int t=0;
				for (int i = 0; i < newnp; i++) {
					if (newptr[i] >= 10000000000 && newptr[i] <= 999999999999 && newptr[i] % 10000000 / 1000000 != 0 && newptr[i] / 10000000 % 1000 / 100 != 0
						&& newptr[i] / 10000000000 != 0)
						t++;
                 }  
				np = t;
			     //allocate dynamic memory
			     phoneptr = new long long[t];
                 int n=0;
                 for(int i=0; i< newnp;i++){
					 if (newptr[i] >= 10000000000 && newptr[i] <= 999999999999 && newptr[i] % 10000000 / 1000000 != 0 && newptr[i] / 10000000 % 1000 / 100 != 0
						 && newptr[i] / 10000000000 != 0) {
						 phoneptr[n] = newptr[i];
						 n++;
					 }
                 }
			}
			else { phoneptr = nullptr;
			      np=0;
			}
		}
		else {
			phoneptr = nullptr;   //set empty state
			*this=Contact();
		}
	}
	Contact::Contact(const Contact& src) {
		strncpy(name, src.name, 19);
		name[19] = '\0';
		np = src.np;
		//allocate dynamic memory 
		if (src.phoneptr != nullptr) {
			phoneptr = new long long[np];
			//copy data from source to new 
			for (int i = 0; i < np; i++) {
				phoneptr[i] = src.phoneptr[i];
			}
		}
		else {
			phoneptr = nullptr;
		}
	}
	Contact& Contact::operator=(const Contact& src) {
		//check self-assignment
		if (this != &src) {
			np = src.np;
			strncpy(name, src.name, 19);
			name[19] = '\0';
			delete[] phoneptr;
			//allocate new dynamic memory
			if (src.phoneptr != nullptr) {
				phoneptr = new long long[np];
				for (int i = 0; i < np;i++) {
					phoneptr[i] = src.phoneptr[i];
				}
			}
			else {
				phoneptr = nullptr;
                                
			}
		}  return *this;
	}
	Contact::~Contact() {
		delete [] phoneptr;
	}

	void Contact::display() const {
		if (!isEmpty()) { //if object not empty display
			cout << name << endl;
			for (int i = 0; i < np; i++) {
				if (phoneptr[i] != 0) {
					long long seven_two = phoneptr[i] % 10000;
					long long seven_one = phoneptr[i] % 10000000 / 10000;
					long long three = phoneptr[i] / 10000000 % 1000;
					long long two = phoneptr[i] / 10000000000;
					cout << "(+" << two << ") " << three << " " << seven_one << "-" << setw(4) <<setfill('0')<< seven_two << endl;
				}
			}
		}
		else if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
	}
	// TODO: implement the isEmpty query
	bool Contact::isEmpty() const {
		bool valid = true;
		//if current object has valid data, then object is not Empty
		if (name[0]!= '\0' || phoneptr != nullptr || np!= 0) {
			valid = false;
		}
		return valid;
	}
	Contact& Contact::operator+=(long long newphone) {
		if (!isEmpty()&&newphone >= 10000000000 && newphone <= 999999999999 && newphone % 10000000 / 1000000 != 0 && newphone / 10000000 % 1000 / 100 != 0
			&& newphone / 10000000000 != 0) {
			Contact tempt = *this;
                                                 np=np+1;
                                                 delete[ ] phoneptr;                   
                                                 phoneptr = new long long[np];
                                                 for (int m = 0; m < np-1 ;m++) {
	                                                phoneptr[m] = tempt.phoneptr[m];
                                                        }			
                        phoneptr[np-1] = newphone;
		}
		return *this;
	}
}
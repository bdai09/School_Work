/**********************************************************
// Workshop 4: Containers
// Notifications.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Oct 2, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/
#include<iostream>
#include"Notifications.h"
#include"Message.h"

using namespace std;

namespace w4 {

	Notifications::Notifications() {	
		numrecord = 0u;
		for (size_t i = 0u;i < SIZE;++i) {
		   msg[i] = nullptr;
		}
	}
	//copy constructor
	Notifications::Notifications(const Notifications& src) {
		for (size_t i = 0u;i < SIZE;++i) {
			msg[i] = nullptr;
		}
		*this = src;
	}
	//copy assignment operator
	Notifications& Notifications::operator=(const Notifications& src) {
		if (this != &src) {
			for (size_t i = 0u;i < numrecord;++i) {
				delete msg[i];
				msg[i] = nullptr;
			}
			this->numrecord = src.numrecord;
			for (size_t i = 0u;i < numrecord;++i) {
			    msg[i] = new Message(*src.msg[i]);
			}
		}
		return *this;
	}
	//move constructor
	Notifications::Notifications(Notifications&& src) {
		*this = move(src);
	}
	//move assignment operator
	Notifications& Notifications::operator=(Notifications&& src) {
		if (this != &src) {
			for (size_t i = 0u;i <SIZE;++i) {
				delete this->msg[i];
				this->msg[i] = nullptr;
				this->msg[i] = src.msg[i];
				src.msg[i] = nullptr;
			}
			this->numrecord = src.numrecord;
		}
		return *this;
	}
	//destructor
	Notifications::~Notifications() {
		for (size_t i = 0u;i < numrecord;++i) {
			delete msg[i];
		}
	}
	void Notifications::operator+=(const Message& srcmsg) {
		if (!srcmsg.empty()) {
			if (numrecord < SIZE) {
				this->msg[numrecord] = new Message(srcmsg);
				numrecord++;
			}
		}
	}
	void Notifications::display(std::ostream& os) const {
		for (size_t i=0u; i < numrecord;i++) {
			if (msg[i] != nullptr)
				msg[i]->display(os);
		}
	}
}
/**********************************************************
// Workshop 4: Containers
// Notifications.h
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
#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H
#include<iostream>
#include "Message.h"

const size_t SIZE = 10;

namespace w4 {
	class Notifications {
		Message* msg[SIZE];
		size_t numrecord;
	public:
		Notifications();
		Notifications(const Notifications& src);
		Notifications& operator=(const Notifications& src);
		//move constructor
		Notifications(Notifications&& src);
		Notifications& operator=(Notifications&& src);
		//destructor
		~Notifications();
		void operator+=(const Message& srcmsg);
		void display(std::ostream& os) const;
	};
}
#endif
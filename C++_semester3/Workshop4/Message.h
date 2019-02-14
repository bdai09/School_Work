/**********************************************************
// Workshop 4: Containers
// Message.h
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
#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H
#include<string>
#include<iostream>
#include<fstream>

namespace w4 {
	class Message {
		std::string username;
		std::string replyname;
		std::string tweetmsg;
	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}
#endif
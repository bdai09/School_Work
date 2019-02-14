/**********************************************************
// Workshop 4: Containers
// Message.cpp
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
#include<fstream>
#include"Message.h"

using namespace std;

namespace w4 {
	Message::Message() {
		username = "";
		replyname = "";
		tweetmsg = ""; //safe empty state
	}
	Message::Message(std::ifstream& in, char c) {
		string str;
		int first_space = 0u;
		if (!in.eof()) {
			if (getline(in, str, c)) {
				first_space = str.find(" ");//find space between user and reply
				username = str.substr(0, first_space);
				if (str.substr(first_space + 1, 1) == "@") { //check if has reply part
					int sec_space = str.find(" ", first_space + 1);
					if (sec_space != -1) {
						replyname = str.substr(first_space + 2, sec_space - first_space - 2);
						tweetmsg = str.substr(sec_space + 1);
					}
					else {
						replyname = str.substr(first_space + 2);
						tweetmsg = "";
					}
				}
				else { //if missing reply part
					replyname = "";
					if (str.find(c) != first_space) {
						tweetmsg = str.substr(first_space + 1);
					}
					else { tweetmsg = ""; }
				}
			}
		}
	}
	bool Message::empty() const {
		if (username == "" || tweetmsg == "")
			return true;
		else
			return false;
	}
	void Message::display(std::ostream& os) const {
		if (!this->empty()) {
			cout << "Message" << endl;
			cout << " User  : " << username << endl;
			if (replyname.length() != 0)
				cout << " Reply : " << replyname << endl;
			cout << " Tweet : " << tweetmsg << endl << endl;
		}
	}
}

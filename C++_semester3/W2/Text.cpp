/**********************************************************
// Workshop 2: Move and Copy Semantics
// Text.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept12, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include"Text.h"

using namespace std;

namespace w2 {
	Text::Text() {
		Strings=nullptr;//safe empty state
		numrecord=0u;
	}
	Text::Text(const string str) {
		string temp;
		size_t line_cnt = 0;
		ifstream fin(str);
		if (fin.is_open()) { //count lines
			while (!fin.eof()) {
				getline(fin, temp);
			      line_cnt++;
			}
			numrecord = line_cnt;
			Strings = new string[line_cnt]; //allocate memory and copy
			fin.clear();//restart to copy
			fin.seekg(0);
			for (size_t i = 0u; i < line_cnt; i++) {
				getline(fin, this->Strings[i]);
			}
			fin.close();
		}
		else {
			Strings = nullptr;
			*this = Text();
		}
	}
	//copy constructor
	Text::Text(const Text& src){
		this->Strings = nullptr;
		*this=src;
	}
	//copy assignment operator
	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			this->numrecord = src.numrecord;
			//delete current object memory
			delete[] this->Strings;
			this->Strings = new string[numrecord];
			for (size_t i=0u;i < numrecord;++i) {
			this->Strings[i].assign(src.Strings[i]);
			}
		}
		return *this; 
	}
	//move constructor
	Text::Text(Text&& src) {
		this->Strings = nullptr;
		*this = move(src);
	}
	//move assignment operator
	Text& Text::operator=(Text&& src) {
		if (this != &src) {
			this->numrecord = src.numrecord;
			//delete current object memory
			delete[] this->Strings;
			this->Strings = src.Strings;
			src.Strings = nullptr;
			src.numrecord = 0u;
		}
		return *this;
	}
	//destructor
	Text::~Text() {
		delete[] Strings;
	}
		
	size_t Text::size() const {
		return numrecord;
	}
	
}
/**********************************************************
// Workshop 2: Move and Copy Semantics
// Text.h
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept12, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/#pragma once
#ifndef W2_TEXT_H
#define W2_TEXT_H


namespace w2 {
	class Text {
		std::string* Strings;
		size_t numrecord;
	public:
		Text();
		Text(const std::string str);
		//copy constructor
		Text(const Text& src);
		//copy assignment operator
		Text& operator=(const Text& src);
		//move constructor
		Text(Text&& src);
		//move assignment operator
		Text& operator=(Text&& src);
		//destructor
		~Text();
		size_t size() const;
	};
}
#endif
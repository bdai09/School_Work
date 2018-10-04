/**********************************************************
// Workshop 3: Templates
// Pair.h
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept24, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/#pragma once
#ifndef PAIR_H
#define PAIR_H


template<typename A, typename B>
class Pair {
	A key;
	B value;
public:
	Pair() { }
	Pair(const A& srckey, const B& srcval) {
		key = srckey; 
		value = srcval;
	}
	const A& getKey() const {return key;}
	const B& getValue() const { return value; }
};
#endif

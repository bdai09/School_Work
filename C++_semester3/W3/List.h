/**********************************************************
// Workshop 3: Templates
// List.h
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept24, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef LIST_H
#define LIST_H

template<typename T, int N>
class List {
	T Array[N];
	T dummy;
	size_t count;
public:
	List() { count = 0u; }
	size_t size() const { return count; } //return number of entries in array
	const T& operator[](int index) const { //return element in array
		if (index >= 0  && index < size() )
			return Array[index];
		else return dummy;
	}
	void operator+=(const T& elem) { //add element to array
		if (count < N)  Array[count++] = elem;
	}
};
#endif

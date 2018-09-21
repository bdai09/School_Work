/**********************************************************
// Workshop 5: Member Operator Overloads-In_Lab
// Fraction.cpp
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/06/14
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: insert header files
#include<iostream>
#include"Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;   //set empty state
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			this->numerator = numerator;
			this->denominator = denominator;
			reduce();
		}
		else {
			this->numerator = 0;   //set empty state
			this->denominator = 0;
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return denominator > numerator ? denominator : numerator;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return denominator < numerator ? denominator : numerator;
	}
	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;
		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int regcd = gcd();
		numerator = numerator / regcd;
		denominator = denominator / regcd;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (!isEmpty() && denominator != 1) { //if object not empty display
			cout << numerator << "/" << denominator;
		}
		else if (!isEmpty() && denominator == 1) {
			cout << numerator;
		}
		else {
			cout << "no fraction stored";
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool valid = true;
		//if denominator and numerator is not 0, then object is not Empty
		if (denominator != 0 || numerator != 0) {
			valid = false;
		}
		return valid;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;
		if (!(this->isEmpty()) && !(rhs.isEmpty())) {
			temp = *this;
			temp.numerator = numerator*rhs.denominator + denominator*rhs.numerator;
			temp.denominator = denominator * rhs.denominator;
			return temp;
		}
		else {
			return temp;
		}
	}
}
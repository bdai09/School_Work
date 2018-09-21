/**********************************************************
// Workshop 5: Member Operator Overloads-At_Home
// Fraction.h
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/06/14
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& ) const;
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		const Fraction& operator+=(const Fraction&);
	};
}
#endif
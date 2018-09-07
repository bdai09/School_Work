/**********************************************************
// Workshop 7: Derived Class-In_Lab
// Hero.h
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/07/12
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
	// TODO: define the Contact class
	const int max_rounds = 100;
	class Hero {
		// TODO: declare instance variables 
		char name[41];
		int health;
		unsigned int attack;
	public:
		// TODO: declare public member functions
		Hero();
		Hero(const char*, int,int);
		//operators
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
	//helper functions
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif
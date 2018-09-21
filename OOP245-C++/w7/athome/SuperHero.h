/**********************************************************
// Workshop 7: Derived Class-At_Home
// Hero.h
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/07/12
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: header file guard
#ifndef SICT_SuperHero_H
#define SICT_SuperHero_H
#include "Hero.h"
// TODO: create namespace
namespace sict {
	//Derive class from Hero
	class SuperHero: public Hero {
		// TODO: declare instance variables 
		unsigned int defend_;
		unsigned int bonus;
	public:
		// TODO: declare public member functions
		SuperHero();
		SuperHero(const char*, int,unsigned int,unsigned int, unsigned int);
		//operators
		//void operator-=(int attack);
		//bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		int defend()const;
		//friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	//helper functions
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif

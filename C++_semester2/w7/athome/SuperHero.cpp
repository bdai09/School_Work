/**********************************************************
// Workshop 7: Derived Class-At_Home
// SuperHero.cpp
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/07/12
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/
// TODO: insert header files
#include<iostream>
#include<cstring>
#include"SuperHero.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	SuperHero::SuperHero():Hero() {
		bonus = 0;
		defend_ = 0;
	}
	// TODO: implement the three-argument constructor
	SuperHero::SuperHero(const char* srcname, int srchealth, unsigned int srcattack, unsigned int bonus, unsigned int defend_):Hero(srcname, srchealth, srcattack){
		bool valid = bonus>0 && defend_ > 0;
		if (valid) {
			//accept data
			this->bonus = bonus;
			this->defend_ = defend_;
		}
		else {
			this->bonus=0;
			this->defend_ = 0;
		}
	}
	//query attack strength
	int SuperHero::attackStrength() const {
		int result;
		if (isEmpty()) {
			result = 0;	 //if safe state 
		}
		else {
			result = Hero::attackStrength()+bonus;
		}
		return result;
	}
	bool SuperHero::isEmpty() const {
		bool valid = true;
		//if current object has valid data, then object is not Empty
		if (!Hero::isEmpty()|| bonus!= 0 || defend_!= 0) {
			valid = false;
		}
		return valid;
	}
	int SuperHero::defend()const {
		int result;
		if (isEmpty()) {
			result = 0;	 //if safe state 
		}
		else {
			result = defend_;
		}
		return result;
	}
	//helper functions
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		bool valid = true;
		SuperHero temp1 = first;
		SuperHero temp2 = second;
		const SuperHero *winner = nullptr;
		//check rounds number and if alive
		int i = 0;
		for (i = 0; i <= max_rounds && valid;i++) {
			temp1 -= (temp2.attackStrength()-temp1.defend());
			temp2 -= (temp1.attackStrength()-temp2.defend());
			valid = temp1.isAlive() && temp2.isAlive();
		}
		//check who is winner
		if (temp1.isAlive() && !temp2.isAlive()) {
			winner = &first;
		}
		else if (temp2.isAlive() && !temp1.isAlive()) {
			winner = &second;
		}
		else {
			winner = &first;
		}
		cout << "Super Fight! " << first << " vs "
			<< second << " : Winner is " << *winner << " in " << i << " rounds." << endl;
		return (*winner);
	}

}
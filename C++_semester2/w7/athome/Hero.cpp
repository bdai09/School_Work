/**********************************************************
// Workshop 7: Derived Class-At_Home
// Hero.cpp
///////////////////////////////////////////////////////////
// Name			Date
// Bo Dai        2018/07/12
Student number:132954173
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: insert header files
#include<iostream>
#include<cstring>
#include"Hero.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack = 0;
	}
	// TODO: implement the three-argument constructor
	Hero::Hero(const char* srcname, int srchealth, int srcattack) {
		bool valid = strlen(srcname) < 41 && srchealth > 0 && srcattack > 0;
		if (valid) {
			//accept data
			strncpy(name, srcname, 40);
			name[40] = '\0';
			health = srchealth;
			attack = srcattack;
		}
		else {
			*this=Hero();
		}
	}
	//overloaded operator receives attack strength
	void Hero::operator-=(int srcattack) {
		if (srcattack > 0) {
			health = health -srcattack;
			if (health < 0) {
				health = 0;
			}
		}
	}
	//check if current object is healthy
	bool Hero::isAlive() const {
		return health > 0;
	}
	//query attack strength
	int Hero::attackStrength() const {
		int result;
		if (isEmpty()) {
			result = 0;	 //if safe state 
		}
		else {
			result = attack;
		}
		return result;
	}
	bool Hero::isEmpty() const {
		bool valid = true;
		//if current object has valid data, then object is not Empty
		if (name[0] != '\0'||health != 0 || attack != 0) {
			valid = false;
		}
		return valid;
	}

    //helper functions
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (!hero.isEmpty()) {
			os << hero.name;
		}
		else {
			cout << "No hero" << endl;
		}
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		bool valid = true;
		Hero temp1 = first;
		Hero temp2 = second;
		const Hero *winner = nullptr;
		//check rounds number and if alive
		int i=0;
		for (i = 0; i <= max_rounds &&valid;i++) {
			temp1 -= temp2.attackStrength();
			temp2 -= temp1.attackStrength();
			valid = temp1.isAlive() && temp2.isAlive();
		}
		//check who is winner
		if (temp1.isAlive()&&!temp2.isAlive()) {
			winner = &first;
		}
		else if (temp2.isAlive() && !temp1.isAlive()) {
			winner = &second;
		}
		else {
			winner = &first;
		}
		cout << "Ancient Battle! " << first << " vs "
			<< second << " : Winner is " << *winner << " in " << i << " rounds." << endl;	
		return (*winner);
	}

}
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0

// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// BO DAI   May24, 2018 
Student number:132954173
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include<iostream>
#include"Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(const Kingdom &queen) {
		cout<<queen.m_name<<", population "<<queen.m_population<<endl;
	}
	void display(const Kingdom *Kingdoms, int numArray) {
		cout << "------------------------------\n"
			<< "Kingdoms of SICT\n"
			<< "------------------------------" << endl;
		int sum = 0;
		int i;
                //for loop to display each Kingdoms and sum
		for (i = 0; i < numArray; i++) {
			cout << i + 1 << ". ";
			display(Kingdoms[i]);
			sum = sum + Kingdoms[i].m_population;

		}
		cout << "------------------------------\n"
			<< "Total population of SICT: " << sum << "\n"
			<< "------------------------------\n" << endl;
	}
}
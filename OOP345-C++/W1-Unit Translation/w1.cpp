/**********************************************************
// Workshop 1: From One Translation Unit to Another
// w1.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Sept10, 2018
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/
#include<iostream>
#include<fstream>
#include"process.h"

using namespace std;

//// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp
extern int STORED;

int main(int argc, char* argv[])
{
	cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << ' ';
	}
	if (argc < 2)
	{
		cout << "\nInsufficient number of arguments\n";
		return 1;
	}

	// TODO: Add code here that will print out max characters
	// stored by your CString object
	cout << "\nMaximum number of characters stored: "<<STORED << endl;
	
	for (int i = 1; i < argc; i++)
	{
		process(argv[i], cout);
	}

	return 0;
}
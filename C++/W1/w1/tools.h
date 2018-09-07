/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code

Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Date: May17, 2018

/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SICT_TOOLS_H
#define SICT_TOOLS_H
namespace sict {
	// Displays the user interface menu
	int menu();
	// Performs a fool-proof integer entry
	int getInt(int min, int max);
}
#endif
#pragma once// Final Project Milestone 4
//iProduct.h interface
// Version 1.0
// Name			   Date
// Bo Dai        2018/08/03
//Student number : 132954173
/////////////////////////////////////////////////////////////////
#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include<fstream>
#include<iostream>

namespace AMA {
	class iProduct {
	public:
		//receive reference to an fstream object, an optional bool, 
		//returns reference to the fstream object
		virtual std::fstream& store(std::fstream& file,bool newLine=true) const=0;

		//returns reference to fstream object
		virtual std::fstream& load(std::fstream& file) = 0;

		//This query receives reference to ostream object,a bool 
		//returns a reference to the ostream object
		virtual std::ostream& write(std::ostream& os,bool linear) const= 0;

		//extracts the data fields for the current object 
		virtual std::istream& read(std::istream& is) = 0;

		//compare string received is identical to the sku or not
		virtual bool operator==(const char*) const = 0;

		//returns total cost of product on hand, taxes included.
		virtual double total_cost() const = 0;

		//resets number of units on hand to number received
		virtual void quantity(int) = 0;

		//returns the address of product name
		virtual const char* name() const = 0;

		//returns the number of units of product needed.
		virtual int qtyNeeded() const = 0;

		//returns the number of product on hand.
		virtual int quantity() const = 0;

		//add receives number of units to updat units on hand
		virtual int operator+=(int) = 0;

		//returns true if the name of the current object 
		//is greater than the name of the referenced object
		virtual bool operator>(const iProduct&) const = 0;
        virtual ~iProduct() {}
	};
	//helper functions

	//this function inserts product record into the ostream
	std::ostream& operator<<(std::ostream&, const iProduct&);

	//extracts the Product record from the istream.
	std::istream& operator>>(std::istream&, iProduct&);

	//add total cost of Product to double received
	double operator+=(double&, const iProduct&);

	//return the address of a Product object
	iProduct* CreateProduct();

	//return the address of a perishable object
	iProduct* CreatePerishable();
}
#endif

// Final Project Milestone 5
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/07/18
//Student number : 132954173
// Description: The Product class is a concrete class that
//encapsulates the general information for an AMA product
/////////////////////////////////////////////////////////////////
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"
#include "iProduct.h"

namespace AMA {
	//pre-defined constants
	const int max_sku_length = 7; //max number of characters in sku
	const int max_unit_length = 10;//max characters in units'description
	const int max_name_length = 75;//max chars in user's name descriptor
	const double tax = 0.13;//tax rate
	//hold general information of the items
	class Product:public iProduct {
		char type; //type of product
		//array holds stock keeping unit, 
		char prod_sku[max_sku_length+1];
		//describe product's unit
		//max number of chars excluding null is MAX_UNIT
		char prod_unit[max_unit_length+1];
		char* prod_name; //hold address of product name in dynamic memory
		int quantity_hand;//product currently on hand
		int quantity_need;//quantity of product needed
		double prod_price; //price of single unit before tax 
		bool istaxable; //true if product is taxable
		ErrorState state_prod; //holds error state of Product object
	protected:
		void name(const char*); //receives address of string holds the name of product name
		const char* name() const; 	//returns the address of product name
		const char* sku() const;   	//returns address of product sku
		const char* unit() const;  	//returns address of the product unit.
		bool taxed() const;  	//returns the taxable status of the product
		double price() const;  	//returns price of a single item of product
		//returns the price of a single item of the product plus any tax that applies to the product
		double cost() const; 	
		//This function receives address of error message,stores in the ErrorState object
		void message(const char*);
		//This function returns true if the ErrorState object is clear; false otherwise.
		bool isClear() const;
	public:
		//Zero-One argument constructors 
		Product(char src_type = 'N');
		//seven argument constructors
		Product(const char* src_sku, const char* src_name, const char* src_unit, int src_hand = 0, 
			bool src_taxable = true, double src_pricebefore = 0, int src_need = 0);
		//copy Constructor
		Product(const Product& copysrc);
		//copy Assignment Operator
		Product& operator=(const Product& copysrc);
		~Product(); //deallocates any memory that has been dynamically allocated

		//receive reference to an fstream object, an optional bool, 
		//returns reference to the fstream object
		std::fstream& store(std::fstream& file, bool newLine=true) const;

		std::fstream& load(std::fstream& file); //returns reference to fstream object

	    //This query receives reference to ostream object,a bool 
        //returns a reference to the ostream object
		std::ostream& write(std::ostream& os, bool linear) const;

		//This modifier receives a reference to an istream object,
		//returns a reference to the istream object
		//extracts the data fields for the current object in the following order, line by line.
		std::istream& read(std::istream& is);

		//compare string received is identical to the sku or not
		bool operator==(const char*) const;
		//returns total cost of all items of product on hand, taxes included.
		double total_cost() const;
		//resets number of units on hand to the number received
		void quantity(int);
		//returns true if object is in safe empty state; false otherwise.
		bool isEmpty() const;
		//returns the number of units of the product that are needed.
		int qtyNeeded() const;
		//returns the number of units of the product that are on hand.
		int quantity() const;

		//returns true if the sku of the current object is greater 
		//than the string stored at the received address
		bool operator>(const char*) const;

		//receives reference to Product object,returns true if the name of the current 
		//object is greater than the name of the referenced Product object
		bool operator>(const iProduct&) const;
		//receives number of units to be added, returns updated number of units on hand
		int operator+=(int);
	
	};
	//helper functions
	//this function will insert a Product record into the ostream
	std::ostream& operator<<(std::ostream&, const iProduct&);
	//this function extracts the Product record from the istream.
	std::istream& operator>>(std::istream&, iProduct&);
	//add total cost of Product to double received, return updated double
	double operator+=(double&, const iProduct&);
}
#endif
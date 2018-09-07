#pragma once
// Final Project Milestone 5
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/08/4
//Student number : 132954173
// Description: The Perishable class is a concrete class that
//encapsulates the information for perishable product
/////////////////////////////////////////////////////////////////
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Product.h"
#include "Date.h"

namespace AMA {
	//perishable class
	class Perishable :public Product {
		Date expire_date; //Date obj hold expiry date
	public:
		//NO argument constructors 
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};
}
#endif
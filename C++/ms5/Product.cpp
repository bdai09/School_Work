// Final Project Milestone 5
//
// Version 1.0
// Name			   Date
// Bo Dai        2018/08/07
//Student number : 132954173
// Description: The Product class is a concrete class that
//encapsulates the general information for an AMA product
/////////////////////////////////////////////////////////////////
#include "Product.h"
#include <cstring>
#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>

namespace AMA {
	//receives address of string holds the name of product name
	void Product::name(const char* src_name) {
		//check if received source name is nullptr address
		if(src_name != nullptr) {	
			if (prod_name != nullptr) {//if prod_name is not empty
				delete[] prod_name; //deallocate memory to clean
			}
			int src_len=strlen(src_name);
			int size;
			//check if source name longer than max_name length
			size = (src_len > max_name_length) ? max_name_length : src_len;
			prod_name = new char[size + 1];//allocate dynamic memory
			strncpy(prod_name, src_name, size);//copy string and assign null terminator
			prod_name[size] = '\0';
		}else{
			delete[] prod_name;
			prod_name = nullptr;
		}
	}

	//this query returns the address of product name
	const char* Product::name() const {
		//if empty or nullptr return nullptr
		if(prod_name[0]=='\0'||prod_name==nullptr)
			return nullptr;
		else 
			return prod_name;//return address of name 
	}

	//This query returns address of product sku
	const char* Product::sku() const {
		return prod_sku;
	}

	//This query returns address of the product unit.
	const char* Product::unit() const {
		return prod_unit;
	}

	//This query returns the taxable status of the product
	bool Product::taxed() const {
		return istaxable;
	}

	//This query returns price of a single item of product
	double Product::price() const {
		return prod_price;
	}

	//This query returns the price of a single item of the 
	//product plus any tax that applies to the product
	double Product::cost() const {
		double cost;
		if (istaxable == true)
			cost=prod_price * (1+tax);
		else
			cost= prod_price;
		return cost;
	}

	//receives address of error message,stores in the ErrorState object
	void Product::message(const char* errormessage) {
		state_prod.message(errormessage);
	}

	//returns true if the ErrorState object is clear; false otherwise.
	bool Product::isClear() const {
		return state_prod.isClear();
	}

	//zero-one argument constructors,default receive value 'N'
	Product::Product(char src_type) {
		type = src_type; //set current object to safe empty state
		prod_sku[0]='\0';
	    prod_unit[0]='\0';
		prod_name = nullptr;
		quantity_hand=0;
		quantity_need=0;
		prod_price=0;  
		istaxable=false; 
	}

	//seven argument constructors
	Product::Product(const char* src_sku, const char* src_name,const char* src_unit, 
		int src_hand, bool src_taxable,double src_pricebefore, int src_need) {
		prod_name = nullptr;
		*this = Product();
		name(src_name); //call name() function to copy src_name
		strncpy(prod_sku,src_sku, max_sku_length);//copy src_sku
		prod_sku[max_sku_length] = '\0';
		strncpy(prod_unit, src_unit, max_unit_length); //copy src_unit
		prod_unit[max_unit_length] = '\0';
		quantity_hand = src_hand;
		quantity_need = src_need;
		prod_price = src_pricebefore;
		istaxable = src_taxable;
	}
	
	//copy Constructor
	Product::Product(const Product& copysrc) {
			prod_name=nullptr;
			*this=copysrc;
	}
	//copy Assignment Operator
	Product& Product::operator=(const Product& copysrc) {
		if (this != &copysrc) { 
	        //check if self assignment
			//shallow copy non-resource variables
			type=copysrc.type;
			name(copysrc.prod_name); //call name() function to copy src_name
			strcpy(prod_sku, copysrc.prod_sku);//copy source object sku
			strcpy(prod_unit, copysrc.prod_unit); //copy source unit
			quantity_hand = copysrc.quantity_hand;
			quantity_need = copysrc.quantity_need;
			prod_price = copysrc.prod_price;
			istaxable = copysrc.istaxable;
			state_prod.message(copysrc.state_prod.message());
		}	
		return *this;
	}

	//deallocates any memory that has been dynamically allocated.
	Product::~Product() {
		delete[] prod_name; //deallocate memory to clean
		prod_name = nullptr;
	}

	//receive reference to an fstream object, an optional bool, 
	//returns reference to the fstream object
	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		char seperate = ',';
		//insert data of current object seperated by comma
		file
			<< type << seperate << prod_sku << seperate << prod_name << seperate
			<< prod_unit << seperate << (taxed()?1:0 )<< seperate << prod_price << seperate << quantity_hand << seperate << quantity_need; //<< seperate << state_prod;
		if (newLine == true) { //if bool parameter true put newline
			file << std::endl;
		}
		return file ;
	}

	//receives reference to fstream object, returns reference to that fstream object
	std::fstream& Product::load(std::fstream& file) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		int taxed_;
		//start to load
		file.getline(sku_, max_sku_length, ',');
		sku_[strlen(sku_)] = '\0';

		file.getline(name, max_name_length, ',');
		name[strlen(name)] = '\0';

		file.getline(unit, max_unit_length, ',');
		unit[strlen(unit)] = '\0';

		file >> taxed_;
		file.ignore(); //clean comma
		file >> price_;
		file.ignore();
		file >> quantity;
		file.ignore();
		file >> qtyNeeded;
		file.ignore();
		*this=Product(sku_, name, unit, quantity, taxed_!= 0, price_, qtyNeeded);
		return file;
	}
	
	//This query receives reference to ostream object,a bool 
	//returns a reference to the ostream object
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (state_prod.isClear()) {
			if (linear == true) { //if bool parameter true output following format
				os << std::left<<std::setw(max_sku_length) << prod_sku << "|";
				os << std::left<<std::setw(20) << prod_name << "|";
				os << std::fixed<<std::right<<std::setprecision(2) <<std::setw(7) << cost() << "|";	
				os << std::right<<std::setw(4) << quantity_hand << "|";
				os << std::left<<std::setw(10) << prod_unit << "|";
				os << std::right<<std::setw(4) << quantity_need << "|";
			}
			else {  //if bool parameter false output following format
				os << " Sku: " << prod_sku << std::endl;
				os << " Name (no spaces): " << prod_name << std::endl;
				os << " Price: " << price() << std::endl;
				if (istaxable)
					os << " Price after tax: " << cost() << std::endl;
				else
					os << " Price after tax: N/A" << std::endl;
				os << " Quantity on Hand: " << quantity_hand <<" "<<prod_unit<< std::endl;
				os << " Quantity needed: " << quantity_need;
			}
		}
		else { os << state_prod; }
		return os;
	}

	//This modifier receives a reference to an istream object,
	//returns a reference to the istream object
	//extracts the data fields for the current object in the following order, line by line.
	std::istream& Product::read(std::istream& is) {
		char input_sku[max_sku_length + 1];
		char input_unit[max_unit_length + 1];
		char input_name[max_name_length+1]; 
		int input_quanhand;
		int input_quanneed;
		double input_price; 
		char tax;
		bool input_taxable; 
		std::cout << " Sku: ";   
		is >> input_sku;  //input sku
		std::cout << " Name (no spaces): ";
		is >> input_name;  //input name
		std::cout << " Unit: ";
		is >> input_unit;  //input unit
		std::cout << " Taxed? (y/n): ";
		is >> tax;   //input answer to char tax and check
		if (tax == 'y' || tax == 'Y' || tax == 'n' || tax == 'N') {
			if (tax == 'y' || tax == 'Y') {    //if tax input is yes
				input_taxable = true;
			}
			else {  //if do not have tax
				input_taxable = false;
			}
		}else { //if user did not put allowed answer
			is.setstate(std::ios::failbit);
			state_prod.message("Only (Y)es or (N)o are acceptable");
		}
		if (!is.fail()) { //if is not failed state, do check with Price input
			std::cout << " Price: ";
			is >> input_price;
			if (is.fail()==true) //if data take in failed,set error message
				state_prod.message("Invalid Price Entry");
		}
		if (!is.fail()) { //if no error continue check quantity
			std::cout << " Quantity on hand: ";
			is >> input_quanhand;
			if (is.fail()==true) //if data take in failed set error message
				state_prod.message("Invalid Quantity Entry");
		}
		if (!is.fail()) { //check quantity needed input
			std::cout << " Quantity needed: ";
			is >> input_quanneed;
			if (is.fail()) 
				state_prod.message("Invalid Quantity Needed Entry");
		}
		if (!is.fail()) { //if success for all data input
			//store inputs group in temporary object
			Product temp=Product(input_sku, input_name,input_unit, input_quanhand, input_taxable, input_price, input_quanneed);
			temp.type = type;
            *this = temp; //copy assignment operator to current object
		}
		is.ignore(); //clear
		return is;
	}

	//compare string received is identical to the sku or not
	bool Product::operator==(const char* string) const {
		bool result = true;
		if (strcmp(prod_sku, string) != 0) {//if not identical,false
			result = false;
		}
		return result;
	}

	//returns total cost of all items of product on hand, taxes included.
	double Product::total_cost() const {
		return cost()*quantity_hand;
	}

	//resets number of units on hand to the number received
	void Product::quantity(int numofunit) {
		quantity_hand = numofunit;
	}

	//returns true if object is in safe empty state; false otherwise.
	bool Product::isEmpty() const {
		bool result = true;
		if (prod_sku[0]!='\0'||prod_unit[0]!='\0'||prod_name!=nullptr||quantity_hand!=0
			||quantity_need!=0||prod_price!=0||istaxable==true||type!='N') {
			result = false;//if any member is not empty 
		}
		return result;
	}

	//returns the number of units of the product that are needed.
	int Product::qtyNeeded() const {
		return quantity_need;
	}

	//returns the number of units of the product that are on hand.
	int Product::quantity() const {
		return quantity_hand;
	}

	//returns true if the sku of the current object is greater 
	//than the string stored at the received address
	bool Product::operator>(const char* src_sku) const {
		//according to how the string comparison functions define ‘greater than’
		bool result = (prod_sku>src_sku);
		return result;
	}

	//receives reference to Product object,returns true if the name of the current 
	//object is greater than the name of the referenced Product object
	bool Product::operator>(const iProduct& srcprod) const {
		bool result = (prod_name>srcprod.name());
		return result;
	}

    //receives number of units to be added, returns updated number of units on hand
	int Product::operator+=(int addunit) {
		if (addunit > 0) {//if received positive value add
				quantity_hand+= addunit;
		}
		return quantity_hand;
	}


	//helper functions

	//this function will insert a Product record into the ostream
	std::ostream& operator<<(std::ostream& ost, const iProduct& product) {
		product.write(ost, true);
		return ost;
	}

	//function extracts the Product record from the istream.
	std::istream& operator>>(std::istream& ist, iProduct& product) {
		product.read(ist);
		return ist;
	}

	//add total cost of Product to double received, return updated double
	double operator+=(double& src_add , const iProduct& product) {
		src_add += product.total_cost();
		return src_add;
	}
}
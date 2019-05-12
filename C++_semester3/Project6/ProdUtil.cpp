#include "ProdUtil.h"
//#include"Product.h"
#include"TaxableProduct.h"
//#include <iostream>
//#include <fstream>
#include<string>
using namespace std;

namespace w6
{
	std::ostream& operator<<(std::ostream& os, const iProduct& src) {
		src.display(os);
		os << endl;
		return os;
	}
	iProduct* readProduct(std::ifstream& is) {
		//string temp;
		//int count = 0;
		//while (getline(is, temp)){
		//	count++;
		//}
		//string temp;
		iProduct* product;
		//getline(is, temp);
		string num = "";
		double price ;
		char taxcheck;
		/**int position1 = temp.find(' ');
		if (position1 != string::npos) {
			num = stoi(temp.substr(0, position1));//123 33
			int position2 = temp.find(position1 + 1, ' ');
			if (position2 != string::npos) {
				temp.erase(0, position1+1);
				cout << "++++++++++++++++++++";
				price = stod(temp.substr(0, position2));
				cout << "++++++++++++++++++++";
				temp.erase(0, position2+1);
				taxcheck=temp[0];
				cout << "++++++++++++++++++++";
				if (taxcheck == 'H' || taxcheck == 'P') {
					product = new w6::TaxableProduct(num, price, taxcheck);
				}
				else {
					string erromessage = "Unrecognizable Tax Code!";
					throw erromessage;
				}
			}
			else {
				temp.erase(0, position1 + 1);
				price = stod(temp.substr(0, temp.find('\n')));
				product = new w6::Product(num, price);
			}
		}**/
		is >> num;
		if(!is.eof()){
			is >> price;
		if (is.peek()!='\n'&& !is.eof()) {
			is >> taxcheck;
			if (taxcheck == 'H' || taxcheck == 'P') {
				product = new w6::TaxableProduct(num, price, taxcheck);
			}
			else {
		       throw "Unrecognizable Tax Code!";
		    }
		}
		else {
		    product = new w6::Product(num, price);
		}
		}
		else {
			product = nullptr;
		}
		return product;
	}
}

#include "TaxableProduct.h"
#include <iomanip>
//#include<cstring>
using namespace std;

namespace w6
{
	TaxableProduct::TaxableProduct():Product() {
		taxcode = ' ';
	}
	TaxableProduct::TaxableProduct(std::string num,double price,char tax) : Product(num,price) {
		taxcode =tax;
	}
	double TaxableProduct::getPrice() const {
		if(taxcode == 'H') return Product::getPrice() * rate[0];
		else return Product::getPrice() * rate[1];
	}
	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		if (taxcode == 'H') {
			os <<" HST";
		}
		if (taxcode == 'P') {
			os << " PST";
		}
	}
}


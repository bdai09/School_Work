
#include "Product.h"
#include <iomanip>
using namespace std;

namespace w6
{
	Product::Product() {
		prod_num = "";
		prod_cost = 0.0;
	}
	Product::Product(string num, double price) {
		prod_num = num;
		prod_cost = price;
	}
	double Product::getPrice() const {
		return prod_cost;
	}
	void Product::display(std::ostream& os) const {
		os << setw(16);
		os << prod_num <<setw(16)<<fixed<< prod_cost;
	}
	
}
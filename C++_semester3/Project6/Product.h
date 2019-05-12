#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include "iProduct.h"

namespace w6
{
	class Product:public iProduct
	{
		std::string prod_num;
		double prod_cost;
	public:
		Product();
		Product(std::string, double);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}
#endif

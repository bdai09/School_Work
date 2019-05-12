#ifndef W6_TAXABLEPRODUT_H
#define W6_TAXABLEPRODUT_H
#include "Product.h"
#include <array>

namespace w6
{
	class TaxableProduct:public Product
	{
		char taxcode;
		std::array<double, 2> rate = { {1.13,1.08} };
	public:
		TaxableProduct();
		TaxableProduct(std::string, double, char);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}
#endif

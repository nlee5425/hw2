#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <set>
#include "product.h"

	class Clothing : public Product {
		public:
			Clothing(const std::string category, const std::string name, double price,
									int qty, std::string size, std::string brand);
			~Clothing(); //book destructor
			
			std::set<std::string> keywords() const; //tested mostly on test if works

			std::string displayString() const;

			void dump(std::ostream& os) const;
			
			
		private:
			std::string clothingsize;
			std::string clothingbrand;


	};

#endif
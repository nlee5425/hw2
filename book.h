#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <set>
#include "product.h"

	class Book : public Product {
		public:
			Book( const std::string category, const std::string name, double price, 
					int qty, std::string isbn, std::string author);
			~Book(); //book destructor
			
			std::set<std::string> keywords() const; //tested mostly on test if works

			std::string displayString() const;

			void dump(std::ostream& os) const;

			
		private:
			std::string isbnnum;
			std::string authorname;


	};

#endif
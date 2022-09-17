#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <set>
#include "product.h"

	class Movie : public Product {
		public:
			Movie( const std::string category, const std::string name, double price,
						int qty, std::string genre, std::string rating);
			~Movie(); //book destructor
			
			std::set<std::string> keywords() const; //tested mostly on test if works

			std::string displayString() const;

			void dump(std::ostream& os) const;
			
			
		private:
			std::string moviegenre;
			std::string movierating;


	};

#endif
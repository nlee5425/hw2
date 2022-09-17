#include "book.h"
#include <iostream>
#include <sstream>
#include <string>
#include "util.h"
#include <set>

using namespace std;
//add code here 
//reference to product.cpp

Book::Book(const std::string category, const std::string name, double price, 
					int qty, std::string isbn, std::string author) : 

					Product(category, name, price, qty)//initializing base class members
{
	//setting priv vars to variables in constructor

	authorname = author;
	isbnnum = isbn;

}
Book::~Book() //book destructor
{

}

std::set<std::string> Book::keywords() const
{
	std::set<std::string>keyword; // creates a set to store the keywords of the specific product for book
	std::set<std::string>keyword_isbn;
	keyword = parseStringToWords(authorname);
	keyword_isbn = parseStringToWords(isbnnum);
	keyword.insert(keyword_isbn.begin() , keyword_isbn.end());//testif this works
	return keyword;
}

std::string Book::displayString() const
{
		std::string displaybook;
		displaybook = name_ + "\n Author: " + authorname + " ISBN: " + isbnnum +"\n" + std::to_string(price_) + " " 
								+ std::to_string(qty_) + "left."; 
		return displaybook;

}

void Book::dump(std::ostream& os) const
{
	std::string display = "Book \n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + 
												"\n" + authorname + "\n" + isbnnum + "\n";
	os << display;
}



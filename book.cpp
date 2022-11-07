#include "book.h"
#include <iostream>
#include <sstream>
#include <string>
#include "util.h"
#include <set>
#include <iomanip>
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

set<string> Book::keywords() const
{
	set<string>keyword; // creates a set to store the keywords of the specific product for book
	set<string>keyword_name;
	keyword = parseStringToWords(authorname);
	keyword_name = parseStringToWords(name_);
	keyword.insert(keyword_name.begin() , keyword_name.end());//testif this works
	keyword.insert(isbnnum);
	return keyword;
}

std::string Book::displayString() const
{	
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string displaybook;
	displaybook = name_ + "\nAuthor: " + authorname + " ISBN: " + isbnnum +"\n" + output + " " 
								+ to_string(qty_) + " left."; 
	return displaybook;

}

void Book::dump(std::ostream& os) const
{ 
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string display = "book\n" + name_ + "\n" + output + "\n" + to_string(qty_) + "\n" + isbnnum +
												"\n" + authorname;
	os << display << endl;
}



#include "clothing.h"
#include <iostream>
#include <sstream>
#include "util.h"
#include <string>
#include <set>

using namespace std;
//add code here 
//reference to product.cpp

Clothing::Clothing(const std::string category, const std::string name, double price,
									int qty, std::string size, std::string brand) : 
					
					Product(category,name, price, qty)//initializing base class members
{
	//setting priv vars to variables in constructor
	clothingsize = size;
	clothingbrand = brand;

}
Clothing::~Clothing() //book destructor
{

}

std::set<std::string> Clothing::keywords() const 
{
	std::set<std::string>keyword; // creates a set to store the keywords of the specific product for book
	std::set<std::string>keyword_brand;
	keyword = parseStringToWords(clothingsize);
	keyword_brand = parseStringToWords(clothingbrand);
	keyword.insert(keyword_brand.begin() , keyword_brand.end());//testif this works
	return keyword;
}

std::string Clothing::displayString() const
{
	std::string displayclothing;
	displayclothing = name_ + "\n Size: " + clothingsize + " Brand: " + clothingbrand +"\n" + std::to_string(price_) + " " 
								+ std::to_string(qty_) + "left."; 
	return displayclothing;
}

void Clothing::dump(std::ostream& os) const
{
	std::string display = "Clothing \n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + 
												"\n" + clothingsize + "\n" + clothingbrand + "\n";
	os << display;

}



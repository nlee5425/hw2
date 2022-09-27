#include "clothing.h"
#include <iostream>
#include <sstream>
#include "util.h"
#include <string>
#include <set>
#include <iomanip>

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

set<string> Clothing::keywords() const 
{
	set<string>keyword_name; // creates a set to store the keywords of the specific product for book
	set<string>keyword_brand;
	keyword_name = parseStringToWords(name_);
	keyword_brand = parseStringToWords(clothingbrand);
	keyword_name.insert(keyword_brand.begin() , keyword_brand.end());//testif this works
	return keyword_name;
}

string Clothing::displayString() const
{
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string displayclothing;
	displayclothing = name_ + "\nSize: " + clothingsize + " Brand: " + clothingbrand +"\n" + output + " " 
								+ to_string(qty_) + " left."; 
	return displayclothing;
}

void Clothing::dump(std::ostream& os) const
{
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string display = "Clothing\n" + name_ + "\n" + output + "\n" + to_string(qty_) + 
												"\n" + clothingsize + "\n" + clothingbrand;
	os << display << endl;

}



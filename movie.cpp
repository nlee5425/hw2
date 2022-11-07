#include "movie.h"
#include <iostream>
#include <sstream>
#include "util.h"
#include <string>
#include <set>
#include <iomanip>

using namespace std;
//add code here 
//reference to product.cpp

Movie::Movie(const std::string category, const std::string name, double price,
						int qty, std::string genre, std::string rating) : 
					
					Product(category, name, price, qty)//initializing base class members
{
	//setting priv vars to variables in constructor
	movierating = rating;
	moviegenre = genre;

}
Movie::~Movie() //book destructor
{

}

set<string> Movie::keywords() const 
{
	set<string>keyword_name; // creates a set to store the keywords of the specific product for book
	set<string>keyword_genre;
	keyword_name = parseStringToWords(name_);
	keyword_genre = parseStringToWords(moviegenre);
	set<string>movieunion;
	movieunion = setUnion(keyword_name , keyword_genre);
	return movieunion;
}

string Movie::displayString() const
{
	stringstream ss; //creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string displaymovie;
	displaymovie = name_  + "\nGenre: " + moviegenre + " Rating: " + movierating +"\n" + output + " " 
								+ to_string(qty_) + " left."; 
	return displaymovie;
}

void Movie::dump(std::ostream& os) const
{
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << price_;
	string output = ss.str();
	string display = "movie\n" + name_ + "\n" + output + "\n" + to_string(qty_) + 
												"\n" + moviegenre + "\n" + movierating;
	os << display << endl;

}



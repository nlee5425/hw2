#include "movie.h"
#include <iostream>
#include <sstream>
#include "util.h"
#include <string>
#include <set>

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

std::set<std::string> Movie::keywords() const 
{
	std::set<std::string>keyword; // creates a set to store the keywords of the specific product for book
	std::set<std::string>keyword_genre;
	keyword = parseStringToWords(movierating);
	keyword_genre = parseStringToWords(moviegenre);
	keyword.insert(keyword_genre.begin() , keyword_genre.end());//testif this works
	return keyword;
}

std::string Movie::displayString() const
{
	std::string displaymovie;
	displaymovie = name_ + "\n Rating: " + movierating + " Genre: " +moviegenre +"\n" + std::to_string(price_) + " " 
								+ std::to_string(qty_) + "left."; 
	return displaymovie;
}

void Movie::dump(std::ostream& os) const
{
	std::string display = displayString();
	os << display << endl;

}



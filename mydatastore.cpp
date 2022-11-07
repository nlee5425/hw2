#include "mydatastore.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;


MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {
	set<Product*>::iterator it;
	for (it = product.begin() ; it != product.end() ; ++it ) {
		delete *it;
	}
	set<User*>::iterator it2;
	for (it2 = userend.begin() ; it2 != userend.end() ; ++it2) {
		delete *it2;
	}
	//seg fault
}

//use a set, the key product will already refer to all the data members in the product
//have to store the products and ewach specific variable corresponding to the product
void MyDataStore::addProduct(Product* p) {
	product.insert(p);
	set<string>::iterator it;
	set<string>wordlist = p->keywords();

	for ( it = wordlist.begin() ; it != wordlist.end() ; ++it) {
		if ( productsearch.find(*it) != productsearch.end()) {
			productsearch[*it].insert(p);
		}
		else {
			set<Product*> productin;
			productin.insert(p);
			productsearch.insert(make_pair((*it), productin));
		}
	}	
}

//use a set, the key username will already refer to all the data members in the user
//have to store the users: username, credit balance, and prime or not
void MyDataStore::addUser(User* u) {
	string username = u->getName();
 	user.insert(make_pair(username, u) );
	userend.insert(u);
}
//and = 0 command do set intersection
//or = 1 command do set union
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
	vector<Product*> phits;
	set<Product*> s1;
	set<Product*> s2;
	int leftoff = 0;
	//call productsearch.find(terms[1])
	if ( terms.size() <= 1) {
		if ( productsearch.find(terms[0]) != productsearch.end()) {
			s1 = productsearch[terms[0]];
		}
	}
	else {
		if (type == 0 ) { //perform and search with vector terms and product search
		for ( unsigned int i = 0;  i < terms.size() ; ++i) {
			
			if (productsearch.find(terms[i]) != productsearch.end()) {
				s1 = productsearch[terms[i]];
				leftoff++;
				break;	
			}
			leftoff++;
		}
		for ( unsigned int i = leftoff ; i < terms.size() ; ++i) {
			if (productsearch.find(terms[i]) != productsearch.end()) {
				s2 = productsearch[terms[i]];
				set<Product*> temp = s1;
				s1 = setIntersection(temp, s2);
			}
		}
		}
		else if ( type == 1 ) { //perform or search
			for ( unsigned int i = 0;  i < terms.size() ; ++i) {
				
				if (productsearch.find(terms[i]) != productsearch.end()) {
					leftoff++;
					s1 = productsearch[terms[i]];
					break;	
				}
				leftoff++;
			}
			for ( unsigned int i = leftoff ; i < terms.size() ; ++i) {
				if (productsearch.find(terms[i]) != productsearch.end()) {
					s2 = productsearch[terms[i]];
					set<Product*> temp;
					temp = setUnion(s1, s2);
					s1 = temp;
				}
			}
		}
	}
	
	set<Product*>::iterator it;
	for ( it = s1.begin() ; it != s1.end() ; ++it ) {
		phits.push_back(*it);
	}
	return phits;
}

//view cart, the user, and whats in the cart (map of vector: key:user and value: items)
void MyDataStore::viewcart(string username) { //access user from username map
	/*vector<Product*> = cart[username]
	User *u
	if cart.find(u) != cart.end()*/
	if (cart.find(username) != cart.end()) { //if they have cart
		vector<Product*> pProducts = cart[username]; //set new vector to the cart of the username
		for ( unsigned int i = 0 ; i < pProducts.size() ; ++i ) { //print out the products
			cout << "Item: " << i + 1 << endl << (pProducts[i])->displayString() << endl << endl;;
		}
	}
	else{
		cout << "Invalid username." << endl;
	}
}

//buy cart refers to both the user, cart, and product STL
//buy cart would deduct product quantity by 1 and deduct user credit amount by product price
void MyDataStore::buycart(string username) {

	//check if there is a user 
	//iterate through all the items
	//check if the item is in stock and if the user has enough credit to purchase the item
	//if user does not have enough money or item is not in stock, move to next item
	if (cart.find(username) != cart.end()) { //user has cart
		vector<Product*> uProducts;
		for ( std::vector<Product *>::iterator it = cart[username].begin() ; it != cart[username].end() ; ++it) {
			double totprice = (*it)->getPrice(); //price of item
			int curqty = (*it)->getQty(); //quantity left of item
			double balanceleft = (user[username])->getBalance();
			if ( curqty > 0 && balanceleft >= totprice) { //if there are products left and user has money to buy
				(*it)->subtractQty(1); //minus quantity of products
				(user[username])->deductAmount(totprice); //deduct price of item from user balance
			}
			else { //if nothing left in stock, move to next product
				uProducts.push_back(*it);
				continue;
			}
		}
		cart[username] = uProducts;
		//cout << "Successfully bought cart." << endl;
	}
	else{
		cout << "Invalid username" << endl;
	}
	
}

//add to cart refers to the product, and add cart STL
void MyDataStore::addcart(string username, Product* p) {
	//check if there is a user 
	//take the index that the user would like to purchase the item in the hits list
	int left = p->getQty();
	if (cart.find(username) != cart.end()) { //if user already has cart, push back the product pointer
		if (left != 0) {
			cart[username].push_back(p);
		}	
		else {
			cout << "Product is out of stock." << endl;
		}
	}
	else if (user.find(username) != user.end() ) { //user doesn't have cart, make the cart for them
		if (left != 0) {
			std::vector<Product*> products;
			products.push_back(p);
			cart.insert( make_pair(username, products));
			cout << "Successfully added to cart!" << endl;
		}
		else {
			cout << "Product is out of stock." << endl;
		}	
	}
	else{ 
		cout << "Invalid request" << endl;
	}
	
}
//dump will just take in the file name and print out all the changes made to the products and users
void MyDataStore::dump(std::ostream& ofile) {
	ofile << "<products>" << endl;
	set<Product*>::iterator it;
	for ( it = product.begin() ; it != product.end() ; ++it) {
		(*it)->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	set<User*>::iterator it2;
	for ( it2 = userend.begin() ; it2 != userend.end() ; ++it2) {
		(*it2)->dump(ofile);
	}
	ofile << "</users>" << endl;
}
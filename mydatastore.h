#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"
// #include "book.h"
// #include "movie.h"
// #include "clothing.h"

class MyDataStore : public DataStore {
	public:

		MyDataStore();

		~MyDataStore();
    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p) override;

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u) override;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile) override;

		void viewcart(std::string username);

		void buycart(std::string username);

		void addcart(std::string username, Product* p);

		private: 
		std::map< std::string, std::set<Product*> > productsearch;
		std::set<Product*> product;
		std::map< std::string, User* > user;
    std::set<User*> userend;
		std::map< std::string, std::vector<Product*> >cart;

};

#endif
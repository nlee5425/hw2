#include "user.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
	stringstream ss;//creating string stream to set decimal places to hundreths
	ss << fixed << setprecision(2) << balance_;
	string output = ss.str();
  os << name_ << " "  << output << " " << type_ << endl;
}

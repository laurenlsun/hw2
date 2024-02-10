#include "user.h"
#include <iostream>
#include <vector>
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{
  std::vector<Product*> cart_;
}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{
  std::vector<Product*> cart_;
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
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

void User::addToCart(Product* p) {
  cart_.push_back(p);
}

void User::viewCart() {
  int num = 1;
  for(int i = 0; i< cart_.size(); i++) {
  // for(std::list<Product*>::iterator it = cart_.begin();
  //   it!=cart_.end();
  //   ++it) {
      cout << "Item " <<  num << endl;
      cout << (cart_[i])->displayString();
      num++;
      cout << endl;
  }

}

void User::buyCart() {
  for(int i=0; i<cart_.size(); i++) {
      // '*it' is a Product*
      cout << "i is currently " << i << endl;
      if (((cart_[i])->getQty() > 0) && (balance_ >= (cart_[i])->getPrice())) {
        // cout << "user.cpp buycart" << endl;
        // cout << "qty before purchase: "<< ((*it)->getQty()) << endl;
        (cart_[i])->subtractQty(1);
        // cout << "qty after purchase: " << ((*it)->getQty()) << endl;
        // cout << "balance before: " << balance_ << endl;
        balance_-=(cart_[i])->getPrice();
        // cout << "balance after: " << balance_ << endl;
        cout << "erasing at index " << i << endl;
        cart_.erase(std::next(cart_.begin(), i));
        --i;
        cout << "i is now " << i << endl;
      }
  }
  
}
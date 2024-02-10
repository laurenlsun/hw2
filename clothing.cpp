#include "clothing.h"
#include "util.h"
#include <iostream>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
  Product(category, name, price, qty)
{
  size_ = size;
  brand_ = brand;
}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> namekws = parseStringToWords(convToLower(name_));
  
  std::set<std::string> brandkws = parseStringToWords(convToLower(brand_));
  namekws = setUnion(namekws, brandkws);
  // cout << name_ << " KEYWORDS:" << endl;
  // for (std::set<std::string>::iterator it=namekws.begin(); it!=namekws.end(); ++it) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  return namekws;
}

std::string Clothing::displayString() const 
{
  return name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Clothing::dump(std::ostream& os) const 
{
  // std::cout << "calling dump on clothing item" << std::endl;
  os << "clothing" << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << size_ << std::endl << brand_ << std::endl;
}

std::string Clothing::getsize() const
{
  return size_;
}

std::string Clothing::getbrand() const
{
  return brand_;
}
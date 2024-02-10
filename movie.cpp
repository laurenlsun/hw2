#include "movie.h"
#include "util.h"
#include <iostream>
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
  Product(category, name, price, qty)
{
  genre_ = genre;
  rating_ = rating;
}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> namekws = parseStringToWords(convToLower(name_));
  // cout << "parseStringToWords on movie: " << endl;
  // for (std::set<std::string>::iterator it=namekws.begin(); it!=namekws.end(); ++it) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  if (namekws.find(convToLower(genre_))==namekws.end())
    namekws.insert(convToLower(genre_));
  
  // cout << name_ << " KEYWORDS:" << endl;
  // for (std::set<std::string>::iterator it=namekws.begin(); it!=namekws.end(); ++it) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  
  return namekws;
}

std::string Movie::displayString() const 
{
  return name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Movie::dump(std::ostream& os) const 
{
  os << "movie" << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << genre_ << std::endl << rating_ << std::endl;
}

std::string Movie::getgenre() const
{
  return genre_;
}

std::string Movie::getrating() const
{
  return rating_;
}
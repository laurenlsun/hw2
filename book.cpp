#include "book.h"
#include "util.h"
#include <iostream>
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
  Product(category, name, price, qty)
{
  isbn_=isbn;
  author_=author;
}

std::set<std::string> Book::keywords() const {
  std::set<std::string> namekws = parseStringToWords(convToLower(name_));
  // cout << "parseStringToWords on book: " << endl;
  // for (std::set<std::string>::iterator it=namekws.begin(); it!=namekws.end(); ++it) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  
  std::set<std::string> authkws = parseStringToWords(convToLower(author_));
  namekws = setUnion(namekws, authkws);
  if (namekws.find(isbn_)==namekws.end())
    namekws.insert(isbn_);

  // cout << name_ << " KEYWORDS:" << endl;
  // for (std::set<std::string>::iterator it=namekws.begin(); it!=namekws.end(); ++it) {
  //   cout << *it << " ";
  // }
  // cout << endl;

  return namekws;
}

std::string Book::displayString() const 
{
  return name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Book::dump(std::ostream& os) const 
{
  os << "book" << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << isbn_ << std::endl << author_ << std::endl;
}

std::string Book::getISBN() const
{
  return isbn_;
}

std::string Book::getAuthor() const
{
  return author_;
}
#include "mydatastore.h"
#include "product.h"
#include "util.h"
#include <iostream>
using namespace std;

MyDataStore::MyDataStore () : DataStore() 
{ 
  std::map<std::string, std::set<Product*>> keywords_;
  std::map<std::string, User*> users_;
}

MyDataStore::~MyDataStore() {
  // create vector of keywords to send to search
  std::vector<std::string> allkws;
  // loop through all keywords
  for (std::map<std::string, std::set<Product*>>::iterator it=keywords_.begin();
    it != keywords_.end();
    ++it) {
      allkws.push_back(it->first);
  }
  std::vector<Product*> allprods = search(allkws, 1);

  // iterate through all products
  for (int i=0; i< allprods.size(); i++) {
    // delete
    delete allprods[i];
  }

  // iterate through all users
  for (std::map<std::string, User*>::iterator it=users_.begin(); 
      it!=users_.end(); it++) {
    // delete
    delete it->second;
  }
}

void MyDataStore::addProduct(Product* p) {
  //get product keywords
  std::set<std::string> prod_kws = p->keywords();
  //iterate through product keywords
  // add product to each keywords' set
  for(std::set<std::string>::iterator it=prod_kws.begin(); it != prod_kws.end(); ++it){
    // check if *it is already a keyword in the big kw map
    if (keywords_.find(*it)==keywords_.end()) {
      // if it isn't, create new k:v with k=*it, v=set<productptr>
      std::set<Product*> prodset;
      prodset.insert(p); // add this product pointer to it
      keywords_[*it] = prodset;
    }
    else // add it to the set
      keywords_[*it].insert(p);
  }
}

void MyDataStore::addUser(User* u) {
  // check if already have user
  if (users_.find(u->getName())==users_.end()) {
    // if user not already in map
    // add entry in map with username:<userObject>
    users_[u->getName()] = u;
  }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::set<Product*> hits;
  std::vector<Product*> hits_ret;

  if (terms.size()==0) {
    return hits_ret;
  }
  else if (terms.size()==1) {
    hits = keywords_[terms[0]];
  }
  else if (type==0) { // AND
    hits = keywords_[terms[0]];
    for (int i=0; i<terms.size(); i++) {
      // cout << "searching term " <<  terms[i] << endl;
      // check if actually in keywords map
      if (keywords_.find(terms[i])!=keywords_.end()) {
        // cout << terms[i] << " is a keyword" << endl;
        // if it is, grab intersection of terms and hits
        // cout << "found the following for keyword " << terms[i] << endl;
        // for (std::set<Product*>::iterator it = keywords_[terms[i]].begin(); it!=keywords_[terms[i]].end(); ++it) {
        //   cout << (*it)->getName() << ", ";
        // }
        // cout << endl;
        hits = setIntersection(hits, keywords_[terms[i]]);
      }
    }
  }
  else if (type==1) { // OR
    for (int i=0; i<terms.size(); i++) {
      if(keywords_.find(terms[i])!= keywords_.end())
        hits = setUnion(hits, keywords_[terms[i]]);
    }
  }

  // copy into vector to return
  for (std::set<Product*>::iterator it = hits.begin();
    it!=hits.end();
    ++it) {
      hits_ret.push_back(*it);
  }
  return hits_ret;
}

void MyDataStore::dump(std::ostream& ofile) {
  
  
  // create vector of keywords to send to search
  std::vector<std::string> allkws;
  // loop through all keywords
  for (std::map<std::string, std::set<Product*>>::iterator it=keywords_.begin();
    it != keywords_.end();
    ++it) {
      allkws.push_back(it->first);
  }
  std::vector<Product*> allprods = search(allkws, 1);

  ofile << "<products>" << std::endl;
  // iterate through all products
  for (int i=0; i< allprods.size(); i++) {
    // print to ofile
    allprods[i]->dump(ofile);
  }
  
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  // loop through all users
  for (std::map<std::string, User*>::iterator it = users_.begin();
    it!=users_.end();
    ++it) {
      it->second->dump(ofile);
  }
  ofile << "</users>" << endl;

}

std::map<std::string, User*> MyDataStore::getUsers() {
  return users_;
}
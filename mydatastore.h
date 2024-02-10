#include "datastore.h"
#include <map>

class MyDataStore : public DataStore {
public:
  MyDataStore();
  ~MyDataStore();
  void addProduct(Product* p);
  void addUser(User* u);
  std::vector<Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);
  std::map<std::string, User*> getUsers();
  std::map<std::string, std::set<Product*>> keywords_;
  std::map<std::string, User*> users_;
};
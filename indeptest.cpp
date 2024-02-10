#include "util.cpp"
#include "iostream"
#include <set>

using namespace std;


int main() {
  std::set<std::string> myset = parseStringToWords("I'll J take a Men's Large pls");
  for (string const& str : myset)
    {
      std::cout << str << ' ';
    }

  std::set<std::string> s1 = {"a", "b", "c", "d"};
  std::set<std::string> s2 = {"c", "d", "e"};
  std::set<std::string> setint = setIntersection(s1, s2);
  std::set<std::string> setun = setUnion(s1,s2);
  cout << "INTERSECTION" << endl;
  for (string const& str : setint)
    std::cout << str << ' ';
  cout << "UNION" << endl;
  for (string const& str : setun)
    std::cout << str << ' ';
}
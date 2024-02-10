#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // declare return set 
  std::set<T> ret;

  // use iterator to iterate thru s1
  for (typename std::set<T>::iterator it = s1.begin(); it!=s1.end(); it++) {
    // check if *it is in s2
    if (s2.find(*it)!=s2.end()) {
      //found thing at `it` in s2
      ret.insert(*it);
    }
  }
  return ret;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  // declare return set 
  std::set<T> ret;

  // use iterator to iterate thru s1
  typename std::set<T>::iterator it;
  //O(n)
  for (it = s1.begin(); it!=s1.end(); it++) {
    // add everything in s1 to ret
    ret.insert(*it);
  }
  // add everything in s2 that's not in s1 to ret
  //O(nlogn)
  for (it = s2.begin(); it!=s2.end(); it++) {
    // check if *it is in s1
    if (s1.find(*it)==s1.end()) {
      // *it not in s1
      ret.insert(*it);
    }
  }
  return ret;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif

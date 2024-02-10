#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  //declare set
  std::set<std::string> ret;
  std::string curr = "";
  //iterate through every character, add to curr string
  //once we hit something that isn't a letter, consider curr string and see if that is a valid keyword
  rawWords = convToLower(rawWords);
  for (int i=0; i<rawWords.length(); i++) {
    // check if in range of normal letters
    if (((rawWords[i] >= 'A')&&(rawWords[i] <= 'Z')) || ((rawWords[i] >='a')&&(rawWords[i] <='z'))) {
      curr += rawWords[i];
    }
    else { // this character isn't a letter
      //check if curr string length >= 2
      if (curr.length()>=2) {
        //if yes check if duplicate kw already exists in set
        if (ret.find(curr)==ret.end())
          ret.insert(curr);
      }
      // reset curr to start keyword from scratch
      curr = "";
    }
  }
  // remember to check last word, which may be kw but not end with space or punctuation
  if (curr.length()>=2) {
    //if yes check if duplicate kw already exists in set
    if (ret.find(curr)==ret.end())
      ret.insert(curr);
  }
  return ret;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

// isAnagram.cpp
// given two strings (s,t) detect if t is an anagram of s
// Connor Green
// 11/13/16

#include <string>
#include <array>
using namespace std;
class Solution{
public:
    bool isAnagram(string s,string t){
      if (s.size()==t.size()){ // check size first, have to be same size
      array <int,26> sarray{}; // create two arrays containg a place for each letter a-z
      array <int,26> tarray{}; // since all lowercase can assume just 26
        for (int a=0; a<s.size(); a++){  // make letter frequency plot
          sarray[s[a]-'a']++; // subtract 'a' when marking frequency to put in range
          tarray[t[a]-'a']++;
        }
      if (sarray==tarray){return 1;}  // equal compares frequency charts
    }                               // if same, anagram so out 1
    return 0; // else not, out 0.
    }
};

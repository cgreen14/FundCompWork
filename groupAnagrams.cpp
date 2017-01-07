// groupAnagrams.cpp
// Connor Green
// given an array of strings group anagrams together
#include <string>
#include <vector>
#include <array>
using namespace std;
class Solution{
public:
  bool isAnagram(string s,string t){   // use is anagram to call in "groupAnagrams"
      if (s.size()==t.size()){
      array <int,26> sarray{};
      array <int,26> tarray{};
        for (int a=0; a<s.size(); a++){
          sarray[s[a]-'a']++;
          tarray[t[a]-'a']++;
        }
      if (sarray==tarray){return 1;}
      }
     return 0;
    }
    // inputing vector string, out put an array of vector strings each containing groups
  vector < vector <string> > groupAnagrams(vector<string> words){
    vector <vector <string> > anagrams;  // initial output container
    anagrams.push_back(vector<string> (1,words[0])); // push back the first value into 2d array
                                      // 1 is used not 0, to avoid segmentation fault
    for(unsigned int i = 0; i< words.size();i++){ // going through words, unsigned since reference size vector
      bool valueAnagram = 0; // this identifies angram presense
      for (int l = 0;l < anagrams.size(); l++){  // starts at front, checks first value in each group of anagram
        if(isAnagram(words[i],anagrams[l][0])==1){ // checks if anagram, using first process
          anagrams[l].push_back(words[i]);  // pushes back into anagram group, not down in larger container
          valueAnagram = 1; // confirms anagram found
          break;
        }
        }
        if (valueAnagram == 0){  // if it gets to the end and an anagram isnt found
          anagrams.push_back(vector<string> (1,words[i]));  // push back simial to line 25, but in the next open space
        }
      }
      return anagrams;  // return 2d vector for display
    }
  };

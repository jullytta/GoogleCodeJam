#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int numTestCases, currTestCase;
  string word;
  list<char> lastWord;

  currTestCase = 1;
  cin >> numTestCases;
  while(currTestCase <= numTestCases){
    cin >> word;

    lastWord.push_back(word[0]);
    for(unsigned int i = 1; i < word.length(); i++){
      if(lastWord.front() <= word[i]){
        lastWord.push_front(word[i]);
      }
      else {
        lastWord.push_back(word[i]);
      }
    }

    cout << "Case #" << currTestCase++ << ": ";
    for(list<char>::iterator it = lastWord.begin();
                             it != lastWord.end();
                             it++){
      cout << (*it);
    }

    cout << endl;

    // CLEAN UP
    lastWord.clear();
  }

  return 0;
}

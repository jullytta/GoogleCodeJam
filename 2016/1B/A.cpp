#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

map<string, int> digitNumber;
map<string, map<char, int>> digitLetters;

void initDigitNumber();
void initDigitLetters();
map<char, int> countLetters(string);
bool canMakeDigit(map<char, int> &, string);

void initDigitNumber(){
  digitNumber["ZERO"] = 0;
  digitNumber["ONE"] = 1;
  digitNumber["TWO"] = 2;
  digitNumber["THREE"] = 3;
  digitNumber["FOUR"] = 4;
  digitNumber["FIVE"] = 5;
  digitNumber["SIX"] = 6;
  digitNumber["SEVEN"] = 7;
  digitNumber["EIGHT"] = 8;
  digitNumber["NINE"] = 9;
}

void initDigitLetters(){
  digitLetters["ZERO"] = countLetters("ZERO");
  digitLetters["ONE"] = countLetters("ONE");
  digitLetters["TWO"] = countLetters("TWO");
  digitLetters["THREE"] = countLetters("THREE");
  digitLetters["FOUR"] = countLetters("FOUR");
  digitLetters["FIVE"] = countLetters("FIVE");
  digitLetters["SIX"] = countLetters("SIX");
  digitLetters["SEVEN"] = countLetters("SEVEN");
  digitLetters["EIGHT"] = countLetters("EIGHT");
  digitLetters["NINE"] = countLetters("NINE");
}

map<char, int> countLetters(string word){
  char letter;
  map<char, int> count;
  stringstream ss;
  
  ss << word;
  for(unsigned i = 0; i < word.size(); i++){
    ss >> letter;
    count[letter]++;
  }

  return count;
}

bool canMakeDigit(map<char, int> &numberOfLetters,
                  string digit){
  for(map<char, int>::iterator it = digitLetters[digit].begin();
                               it != digitLetters[digit].end();
                               it++){
    if( (*it).second > numberOfLetters[(*it).first]){
      return false;
    }
  }
  return true;
}

void makeDigit(map<char, int> &numberOfLetters,
               vector<int> &digits,
               string digit){
  for(map<char, int>::iterator it = digitLetters[digit].begin();
                               it != digitLetters[digit].end();
                               it++){
    numberOfLetters[(*it).first] -= (*it).second;
  }
  digits.push_back(digitNumber[digit]);
}

int main(){
  int numTestCases, currTestCase;
  string phoneString;
  vector<int> digits;
  map<char, int> numberOfLetters;
  initDigitNumber();
  initDigitLetters();

  currTestCase = 1;
  cin >> numTestCases;
  while(currTestCase <= numTestCases){
    cin >> phoneString;
    
    numberOfLetters = countLetters(phoneString);

    // Only zero has a Z
    while(numberOfLetters['Z'] > 0){
      makeDigit(numberOfLetters, digits, "ZERO");  
    }

    // Only two has a W
    while(numberOfLetters['W'] > 0){
      makeDigit(numberOfLetters, digits, "TWO");  
    }

    // Only four has a U
    while(numberOfLetters['U'] > 0){
      makeDigit(numberOfLetters, digits, "FOUR");  
    }

    // At this point, only three has a R
    while(numberOfLetters['R'] > 0){
      makeDigit(numberOfLetters, digits, "THREE");  
    }

    // At this point, only one has an O
    while(numberOfLetters['O'] > 0){
      makeDigit(numberOfLetters, digits, "ONE");  
    }  

    // At this point, only five have a F
    while(numberOfLetters['F'] > 0){
      makeDigit(numberOfLetters, digits, "FIVE");  
    }

    // Only six has a X
    while(numberOfLetters['X'] > 0){
      makeDigit(numberOfLetters, digits, "SIX");  
    }

    // At this point, only seven has a S
    while(numberOfLetters['S'] > 0){
      makeDigit(numberOfLetters, digits, "SEVEN");  
    }

    // Only eight has a G
    while(numberOfLetters['G'] > 0){
      makeDigit(numberOfLetters, digits, "EIGHT");  
    }

    // At this point, only nine has a N
    while(numberOfLetters['N'] > 0){
      makeDigit(numberOfLetters, digits, "NINE");  
    }

    sort(digits.begin(), digits.end());
    cout << "Case #" << currTestCase++ << ": ";
    for(vector<int>::iterator it = digits.begin();
                              it != digits.end();
                              it++){
      cout << (*it);
    }
    cout << endl;

    // CLEAN UP
    numberOfLetters.clear();
    digits.clear();
  }

  return 0;
}

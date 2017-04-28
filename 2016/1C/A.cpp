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

int main(){
  int numTestCases, currTestCase;
  int nParties, nSenators, senatorsIn, partiesIn;
  vector<pair<int, char>> senators;
  
  currTestCase = 1;
  cin >> numTestCases;
  while(currTestCase <= numTestCases){
    cin >> nParties;
    senators.resize(nParties);
    
    senatorsIn = 0;
    // Not my brightest idea
    // Used just to keep track of how many parties are still left
    // I could just use senators.size(), but then I would have to
    // remove elements that become zero, and honestly I don't want to.
    partiesIn = nParties;
    
    for(int i = 0; i < nParties; i++){
      cin >> nSenators;
      senatorsIn += nSenators;
      senators[i] = make_pair(nSenators, 'A' + i);
    }
    
    cout << "Case #" << currTestCase++ << ":";
    while(partiesIn > 0){
      cout << " ";

      sort(senators.rbegin(), senators.rend());

      // Always remove one from each of the two greatest parties,
      // ensuring we will keep the balance UNLESS
      // there are only three guys left
      if(partiesIn >= 2 && senatorsIn != 3){
        senators[0].first--;
        senators[1].first--;

        cout << senators[0].second << senators[1].second;

        if(senators[0].first == 0) partiesIn--;
        if(senators[1].first == 0) partiesIn--;

        senatorsIn -= 2;
      }
      // In that case, one guy has to go out first, otherwise
      // he would be alone and become absolute majority.
      else {
        senators[0].first--;
        cout << senators[0].second;
        if(senators[0].first == 0) partiesIn--;
        senatorsIn--;
      }
    }
    cout << endl;
    
    senators.clear();
  }
  
  return 0;
}

// This solution passes the small input, but not the large.

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

#define MAX_N 1000

using namespace std;

char order[6];
char stable[MAX_N];
int possibilities[MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    // Empty cell
    stable[i] = '.';
  }
}

// Create a priority for each type of unicorn
// first by number of colors,
// then by number of unicorns with these colors
void findOrder(map<char, int> &unicorns){
  vector<pair<int, char>> v;
  v.push_back(make_pair(unicorns['G'], 'G'));
  v.push_back(make_pair(unicorns['O'], 'O'));
  v.push_back(make_pair(unicorns['V'], 'V'));

  sort(v.rbegin(), v.rend());

  for(int i = 0; i < 3; i++){
    order[i] = v[i].second;
  }

  v.clear();

  v.push_back(make_pair(unicorns['Y'], 'Y'));
  v.push_back(make_pair(unicorns['B'], 'B'));
  v.push_back(make_pair(unicorns['R'], 'R'));

  sort(v.rbegin(), v.rend());

  for(int i = 3; i < 6; i++){
    order[i] = v[i-3].second;
  }

}

bool shareColors(char uni1, char uni2){
  // Same color
  if(uni1 == uni2)
    return true;

  if((uni1 == 'R' && uni2 == 'O') ||
     (uni1 == 'O' && uni2 == 'R'))
    return true;

  if((uni1 == 'Y' && uni2 == 'O') ||
     (uni1 == 'O' && uni2 == 'Y'))
    return true;

  if((uni1 == 'B' && uni2 == 'G') ||
     (uni1 == 'G' && uni2 == 'B'))
    return true;

  if((uni1 == 'Y' && uni2 == 'G') ||
     (uni1 == 'G' && uni2 == 'Y'))
    return true;

  if((uni1 == 'B' && uni2 == 'V') ||
     (uni1 == 'V' && uni2 == 'B'))
    return true;

  if((uni1 == 'R' && uni2 == 'V') ||
     (uni1 == 'V' && uni2 == 'R'))
    return true;

  return false;
}

// unicorn can be placed at pos
bool fits(int pos, int n, char unicorn){
  // Check left neigh-bor
  int left = pos-1 >= 0 ? pos-1: n-1;

  // There's an unicorn there, and it's not compatible
  if(stable[left] != '.' && shareColors(stable[left], unicorn)){
    return false;
  }

  // Check right neigh-bor
  int right = pos+1 < n ? pos+1: 0;

  if(stable[right] != '.' && shareColors(stable[right], unicorn)){
    return false;
  }

  return true;
}

int main(){
  int numTestCases, currTestCase;
  int n, r, o, y, g, b, v;
  map<char, int> unicorns;

  currTestCase = 1;
  cin >> numTestCases;
  while(currTestCase <= numTestCases){
    cin >> n >> r >> o >> y >> g >> b >> v;
    init(n);
    bool impossible = false;
    int positioned = 0;

    unicorns['R'] = r;
    unicorns['O'] = o;
    unicorns['Y'] = y;
    unicorns['G'] = g;
    unicorns['B'] = b;
    unicorns['V'] = v;

    while(positioned < n){
      int minPossibilities = -1;
      int nextPos;
      // Fill the position that fits the smallest
      // number of unicorns
      for(int i = 0; i < n; i++){
        possibilities[i] = 0;
        if(fits(i, n, 'R')) possibilities[i] += unicorns['R'];
        if(fits(i, n, 'O')) possibilities[i] += unicorns['O'];
        if(fits(i, n, 'Y')) possibilities[i] += unicorns['Y'];
        if(fits(i, n, 'G')) possibilities[i] += unicorns['G'];
        if(fits(i, n, 'B')) possibilities[i] += unicorns['B'];
        if(fits(i, n, 'V')) possibilities[i] += unicorns['V'];

        if(stable[i] == '.' && (minPossibilities == -1 || minPossibilities > possibilities[i])){
          minPossibilities = possibilities[i];
          nextPos = i;
        }
      }

      // Prioritize unicorns that have more colors
      findOrder(unicorns);

      for(int k = 0; k < 6; k++){
        if(unicorns[order[k]] > 0 && fits(nextPos, n, order[k])){
          // Position the unicorn
          stable[nextPos] = order[k];
          unicorns[order[k]]--;
          positioned++;
          break;
        }
      }

      // No unicorn to place: impossible to solve
      if(stable[nextPos] == '.'){
        impossible = true;
        break;
      }  
    }
    
    cout << "Case #" << currTestCase++ << ": ";
    if(impossible){
      cout << "IMPOSSIBLE" << endl; 
    }
    else {
      for(int i = 0; i < n; i++){
        cout << stable[i];
      }
      cout << endl;
    }

    // CLEAN UP
    unicorns.clear();
  }

  return 0;
}

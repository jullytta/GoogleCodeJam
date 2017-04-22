#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main(){
  int numTestCases, currTestCase;
  int n;
  long double d, k, s;

  currTestCase = 1;
  cin >> numTestCases;
  while(currTestCase <= numTestCases){
    cin >> d >> n;
    
    long double maxDuration = 0;
    for(int i = 0; i < n; i++){
      cin >> k >> s;
      long double duration = (d-k)/s;

      if(duration > maxDuration){
        maxDuration = duration;
      }
    }

    long double maxSpeed = d/maxDuration;

    cout << "Case #" << currTestCase++ << ": ";
    cout << setprecision(10) << maxSpeed;
    cout << endl;

    // CLEAN UP
  }

  return 0;
}

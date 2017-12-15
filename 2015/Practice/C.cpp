#include <iostream>
#include <cilk/cilk.h>

using namespace std;

int main() {
  int n_voters, vote;
  cin >> n_voters;

  for(int i = 0; i < n_voters; i++){
    cin >> vote;
    cout << "Voter " << i+1 << " voted in " << vote << endl;
  }

  return 0;
}
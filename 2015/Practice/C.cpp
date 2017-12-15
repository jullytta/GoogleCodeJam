#include <iostream>
#include <vector>
#include <cilk/cilk.h>
#include "input/test_1.h"

using namespace std;

int main() {

  for(long long i = 0; i < GetN(); i++){
    cout << "Voter " << i << " voted in " << GetVote(i) << endl;
  }

  return 0;

}
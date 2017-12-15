#include <iostream>
#include <vector>
#include <cilk/cilk.h>
#include "input/test_1.h"

using namespace std;

int main() {

  /* Find a suspect of being the majority */
  long long current_suspect, number_of_votes = 0;
  for(long long i = 0; i < GetN(); i++){
    if(number_of_votes == 0){
      current_suspect = GetVote(i);
      number_of_votes++;
    }
    else {
      if(current_suspect == GetVote(i)){
        number_of_votes++;
      }
      else {
        number_of_votes--;
      }
    }
  }

  /* Checks if the suspect actually won */
  long long total_votes = 0;
  for(long long i = 0; i < GetN(); i++){
    if(GetVote(i) == current_suspect){
      total_votes++;
    }
  }

  /* More than half of the votes = majority */
  if(total_votes > GetN()/2){
    cout << current_suspect << endl;
  }
  else {
    cout << "NO WINNER" << endl;
  }

  return 0;

}
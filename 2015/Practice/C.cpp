#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h>
#include <iostream>
#include <vector>
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
  cilk::reducer< cilk::op_add<int> > total_votes(0);
  cilk_for(long long i = 0; i < GetN(); i++){
    if(GetVote(i) == current_suspect){
      *total_votes += 1;
    }
  }

  /* More than half of the votes = majority */
  if(total_votes.get_value() > GetN()/2){
    cout << current_suspect << endl;
  }
  else {
    cout << "NO WINNER" << endl;
  }

  return 0;

}
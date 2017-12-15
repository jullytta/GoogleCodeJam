#include <iostream>
#include <vector>
#include <cilk/cilk.h>

using namespace std;

/* Simulating the API */
/*   in a naive way   */
int n_voters;
vector<int> votes;

void init(){
  int n_voters, vote;
  cin >> n_voters;

  for(int i = 0; i < n_voters; i++){
    cin >> vote;
    votes.push_back(vote);
  }
}

int GetN(){
  return n_voters;
}

int GetVote(int i){
  return votes[i];
}

int main() {

  init();

  cout << GetVote(1) << endl;

  return 0;

}
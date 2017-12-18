#include <iostream>
#include <vector>
#include "input/test_1.h"

/* 'long long' is a long name for a type */
#define ll long long

using namespace std;

/* Finds a suspect of being the majority    */
/* analyzing the votes between [begin, end] */
/* Divide and conquer strategy              */
/* Returns a pair <suspect, vote_count>     */
/* If suspect == -1 no suspect was found    */
pair<ll, ll> find_suspect(ll begin, ll end){
  pair<ll, ll> suspect_1, suspect_2;

  /* More than 2 elements: partitions! */
  if(end - begin > 1){
    ll middle = (begin + end + 1)/2;

    /* Avoiding the invalid use of ‘_Cilk_spawn’ error */
    suspect_1 = find_suspect(begin, middle);
    suspect_2 = find_suspect(middle+1,end);
  }
  /* 1 or 2 elements */
  else {
    /* Only one element in this partition */
    /* Therefore, it's the suspect!       */
    if(begin == end){
      return make_pair(GetVote(begin), 1);
    }
    /* Two elements: we might have a suspect */
    /* if and only if the votes are equal    */
    if(GetVote(begin) == GetVote(end)){
      return make_pair(GetVote(begin), 2);
    }
    else {
      /* No suspect found */
      return make_pair(-1, 0);
    }
  }

  /* Which of the two suspects found has more votes? */
  /* If there is no suspect 1, return suspect 2 */
  if(suspect_1.first == -1)
    return suspect_2;
  /* If there is a suspect 1, but they have less votes */
  /* than suspect 2, subtract the votes and return 2   */
  else if (suspect_1.second < suspect_2.second)
    return make_pair(suspect_2.first, suspect_2.second - suspect_1.second);
  /* Finally, if suspect 2 doesn't exist or have less  */
  /* votes than 1, return 1 with the votes subtracted  */
  else
    return make_pair(suspect_1.first, suspect_1.second - suspect_2.second);

}

int main() {

  pair<ll, ll> suspect = find_suspect(0, GetN()-1);

  /* If we have no suspect, we have no winner! */
  if(suspect.first == -1)
    cout << "NO WINNER" << endl;
  else {
    /* Checks if the suspect actually won */
    ll total_votes = 0;
    for(ll i = 0; i < GetN(); i++){
      if(GetVote(i) == suspect.first){
        total_votes += 1;
      }
    }

    /* More than half of the votes = majority */
    if(total_votes > GetN()/2){
      cout << suspect.first << endl;
    }
    else {
      cout << "NO WINNER" << endl;
    }
  }
  
  return 0;

}
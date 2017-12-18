#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

/* 'long long' is a long name for a type */
#define ll long long
#define N_VOTERS 1000
#define MAX_CANDIDATES 100

using namespace std;

int main() {

  srand(time(NULL));
  
  cout << "// Automatically generated random input" << endl;
  cout << "#include <cassert>" << endl;
  cout << "long long GetN() {" << endl;
  cout << "  return " << N_VOTERS << "LL;" << endl;
  cout << "}" << endl << endl;

  cout << "long long GetVote(long long i) {" << endl;
  cout << "  switch ((int)i) {" << endl;
  
  for(ll i = 0; i < N_VOTERS; i++){
    cout << "    case " << i << ": return " << rand()%MAX_CANDIDATES << "LL;" << endl;
  }

  cout << "    default: assert(0);" << endl;
  cout << "  }" << endl;
  cout << "}" << endl << endl;

  return 0;

}
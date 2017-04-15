#include <iostream>

using namespace std;

// Returns true if flip succeeded, false otherwise
bool flip(string &pancakes, int start, int k, int max_k){
   if(start+k > max_k)
      return false;

   for(int i = start; i < start+k; i++){
      if(pancakes[i] == '+')
         pancakes[i] = '-';
      else pancakes[i] = '+';
   }
   
   return true;
}

int main(){
   bool possible;
   int nTestCases, currTest = 1, k, flips, size;
   string pancakes;

   cin >> nTestCases;
   while(currTest <= nTestCases){
      cin >> pancakes >> k;
      flips = 0;
      size = pancakes.length();
      possible = true;

      for(int i = 0; i < size; i++){
         if(pancakes[i] == '-'){
            if(flip(pancakes, i, k, size)){
               flips++;
            }
            else {
               possible = false;
               break;
            }
         }
      }

      cout << "Case #" << currTest++ << ": ";
      if(possible)
         cout << flips;
      else
         cout << "IMPOSSIBLE";
      cout << endl;
   }

   return 0;
}
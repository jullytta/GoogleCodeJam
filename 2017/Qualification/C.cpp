#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(){
   int nTestCases, currTest = 1;
   long long max, min;
   long long alreadyIn, maxEmpty;
   long long n, k;
   priority_queue<long long> emptyStalls;

   cin >> nTestCases;
   while(currTest <= nTestCases){
      cin >> n >> k;
      emptyStalls.push(n);
      alreadyIn = 0;

      while(alreadyIn < k){
         alreadyIn++;
         maxEmpty = emptyStalls.top();
         
         emptyStalls.pop();
         // Even case
         if(maxEmpty%2 == 0){
            max = maxEmpty/2;
            min = max - 1;
         }
         
         // Odd case
         else {
            max = min = (maxEmpty - 1)/2;
         }
         
         emptyStalls.push(max);
         emptyStalls.push(min);
      }

      cout << "Case #" << currTest++ << ": "
           << max << " " << min << endl;

      emptyStalls = priority_queue<long long>();
   }

   return 0;
}
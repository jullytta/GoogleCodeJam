#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
   int testCases, currTest = 1;
   long long result;
   string n;

   cin >> testCases;
   while(currTest <= testCases){
      cin >> n;
      reverse(n.begin(), n.end());

      for(unsigned i = 0; i < n.length()-1; i++){
         int curr, next;
         stringstream ssC, ssN;

         ssC << n[i];
         ssC >> curr;

         ssN << n[i+1];
         ssN >> next;
         
         if(curr < next){
            next--;
            n[i+1] = to_string(next)[0];
            for(unsigned j = 0; j < i+1; j++){
               n[j] = to_string(9)[0];
            }
         }
      }
   
      reverse(n.begin(), n.end());
      
      stringstream ss;
      ss << n;
      ss >> result;
      cout << "Case #" << currTest++ << ": " << result << endl;
   }

   return 0;
}
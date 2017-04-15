// I am not proud of this program.
// Please disregard it.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

#define MAX_GRID_SIZE 100

using namespace std;

char stage[MAX_GRID_SIZE][MAX_GRID_SIZE];

void printStage(int gridSize){
   for(int i = 0; i < gridSize; i++){
      for(int j = 0; j < gridSize; j++){
         cout << stage[i][j];
      }
      cout << endl;
   }
}

void change(int posX, int posY,
            char target,
            map<char, int> &worth,
            vector<string> &changes,
            int &points,
            int &upgrades){

   points = points - worth[stage[posX][posY]]
                   + worth[target];
   upgrades++;
   stage[posX][posY] = target;
   stringstream ss;
   ss << target << " " << posX+1 << " " << posY+1;
   changes.push_back(ss.str());
}

// Returns true if m1 and m2 can be
// on the same row/column, false otherwise.
bool validPairRC(char m1, char m2){
   return m1 == '+' || m2 == '+';
}

// Returns true if m1 and m2 can be on the
// same diagonal, false otherwise.
bool validPairD(char m1, char m2){
   return m1 == 'x' || m2 == 'x';
}

// Returns true if (posX, posY) on the grid
// can become 'target'
bool canBeChanged(int gridSize,
                  int posX, int posY,
                  char target){
   char other;
   int otherX, otherY;

   // Check the model's column
   for(int i = 0; i < gridSize; i++){
      other = stage[i][posY];
      // If not themselves and there's a model there
      if(i != posX && other != '.'
                   // and its not possible to become target
                   && !validPairRC(target, other)){
         return false;
      }
   }

   // Check the model's row
   for(int j = 0; j < gridSize; j++){
      other = stage[posX][j];
      if(j != posY && other != '.'
                   && !validPairRC(target, other)){
         return false;
      }
   }

   // Check the model's diagonal
   otherX = posX-1; otherY = posY-1;
   while(otherX >= 0 && otherY >= 0){
      other = stage[otherX][otherY];
      if(other != '.' && !validPairD(target, other)){
         return false;
      }
      otherX--; otherY--;
   }

   otherX = posX+1; otherY = posY+1;
   while(otherX < gridSize && otherY < gridSize){
      other = stage[otherX][otherY];
      if(other != '.' && !validPairD(target, other)){
         return false;
      }
      otherX++; otherY++;
   }

   // Check the model's antidiagonal
   otherX = posX+1; otherY = posY-1;
   while(otherX < gridSize && otherY >= 0){
      other = stage[otherX][otherY];
      if(other != '.' && !validPairD(target, other)){
         return false;
      }
      otherX++; otherY--; 
   }

   otherX = posX-1; otherY = posY+1;
   while(otherX >= 0 && otherY < gridSize){
      other = stage[otherX][otherY];
      if(other != '.' && !validPairD(target, other)){
         return false;
      }
      otherX--; otherY++; 
   }

   return true;
}

void bestFit(int posX, int posY,
            map<char, int> &worth,
            vector<string> &changes,
            int &points,
            int &upgrades,
            int gridSize){
   if(stage[posX][posY] != '.'){
      return;
   }

   if(canBeChanged(gridSize, posX, posY, 'o')){
      change(posX, posY, 'o', worth, changes, points, upgrades);
   } else if(canBeChanged(gridSize, posX, posY, '+')) {
      change(posX, posY, '+', worth, changes, points, upgrades);
   } else if(canBeChanged(gridSize, posX, posY, 'x')) {
      change(posX, posY, 'x', worth, changes, points, upgrades);
   }
}

int main(){
   int nTestCases, currTest = 1;
   int points, upgrades;
   int gridSize, nModels;
   vector< pair<int, int> > upgradable;
   vector<string> changes;
   map<char, int> worth;

   worth['.'] = 0;
   worth['x'] = 1;
   worth['+'] = 1;
   worth['o'] = 2;

   cin >> nTestCases;
   while(currTest <= nTestCases){
      points = upgrades = 0;
      cin >> gridSize >> nModels;

      // Prepare stage
      for(int i = 0; i < gridSize; i++)
         for(int j = 0; j < gridSize; j++)
            stage[i][j] = '.';

      // Place initial models
      for(int i = 0; i < nModels; i++){
         char model;
         int posX, posY;
         cin >> model >> posX >> posY;
         stage[--posX][--posY] = model;
         points += worth[model];
         if(model != 'o'){
            upgradable.push_back(make_pair(posX, posY));
         }
      }

      // Last line first
      for(int j = 0; j < gridSize; j++){
         bestFit(gridSize-1, j, worth, changes, points, upgrades, gridSize);
      }

      // Try to upgrade them
      for(vector< pair<int, int> >::iterator it = upgradable.begin();
                                             it != upgradable.end();
                                             it++){
         int posX = (*it).first;
         int posY = (*it).second;
         bool canUpgrade = canBeChanged(gridSize, posX, posY, 'o');

         if(canUpgrade){
            change(posX, posY, 'o', worth, changes, points, upgrades);
         }
      }

      // Now for each empty position, try to fit either an 'o',
      // a '+' or a 'x'
      for(int i = 0; i < gridSize; i++){
         for(int j = 0; j < gridSize; j++){
            bestFit(i, j, worth, changes, points, upgrades, gridSize);
         }
      }

      //printStage(gridSize);

      cout << "Case #" << currTest++ << ": "
           << points << " " << upgrades << endl;

      for(vector<string>::iterator it = changes.begin(); it != changes.end(); it++){
         cout << (*it) << endl;
      }

      upgradable.clear();
      changes.clear();
   }

   return 0;
}
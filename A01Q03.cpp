// Name: Oishe Farhan
// Date 17-01-2017
// Title: A01Q03

#include <stdio.h>
// #include <stdlib.h>
#include <time.h>
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <algorithm>
#include <vector>
//Number of bottles and caps in case
#define NUM 15

using namespace std;

void Randomize(vector<int>& bottles, vector<int>& caps){
  //Randomly fill up bottles and caps with unique numbers

  // bottles = {6,4,2,3,1,5};
  // caps = {5,1,2,4,3,6};

  srand(time(NULL)); //seed for random number

  bottles[0] = 0;
  caps[0] = 0;
  for(int i=1; i<NUM; i++)
  {
    int randB = rand()%i;
    int randC = rand()%i;
    bottles[i] = bottles[randB];
    caps[i] = caps[randC];
    bottles[randB] = i;
    caps [randC] = i;
  }
}

void printCase(vector<int>& bottles, vector<int>& caps){
  //Display bottles and caps
  cout << "Bottles:\n";
  for (int i = 0; i<NUM ; ++i){
    cout.width(2);
    cout << right << bottles[i] << '|';
  }
  cout << "\nCaps:\n";
  for (int i = 0; i<NUM; ++i)
  {
    cout.width(2);
    cout << right << caps[i] << '|';
  }
  cout << endl << "-----------------"<< endl;
}


int main(){
  vector<int> bottles;
  vector<int> caps;
  bottles.reserve(NUM);
  caps.reserve(NUM);
  // printCase(bottles, caps);
  Randomize(bottles, caps);
  printCase(bottles, caps);
  // int size = bottles.size();

  // int middle = size/2;
  // for (int a = 0)



}

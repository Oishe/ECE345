
Skip to content
This repository

    Pull requests
    Issues
    Gist

    @Oishe

1
0

    0

Oishe/ECE345
Code
Issues 0
Pull requests 0
Projects 0
Wiki
Pulse
Graphs
Settings
ECE345/quicksort.cpp
2b2d490 7 days ago
@Oishe Oishe I'm uploading all the code I've worked on so far:
64 lines (56 sloc) 1.15 KB
// Name: Oishe Farhan
// Date 19-01-2017
// Title: quicksort
#include <stdio.h>
#include <time.h>
#include <vector>
#define MAX 20

using namespace std;

void Randomize(vector<int>& array){
  srand(time(NULL));
  for(int i=0; i<MAX; i++){
    array[i]=rand()%MAX;
  }
}

void printArray(vector<int>& array){
  for(int i=0; i<MAX; i++){
    cout.width(2);
    cout <<right<<array[i]<<"|";
  }
  cout <<endl<<"------------------"<<endl;
}

int partition (vector<int>& array, int L, int R){
  int pivot = array[R];
  int i = L-1;
  for(int j=L; j<R; j++){
    if(array[j]<=pivot){
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  i++;
  int temp = array[i];
  array[i] = array[R];
  array[R] = temp;
  return i;
}

 void quicksort(vector<int>& array, int L, int R){
   //quicksort recursive method
   //P=pivot L=left R=right
   if (L<R){
     int P = partition(array,L,R);
     quicksort(array,L,P-1);
     quicksort(array,P+1,R);
   }

 }

int main(int argc, char const *argv[]) {
  vector<int> array;
  array.reserve(MAX);
  Randomize(array);
  printArray(array);
  quicksort(array,0,MAX);
  printArray(array);
  return 0;
}

    Contact GitHub API Training Shop Blog About

    © 2017 GitHub, Inc. Terms Privacy Security Status Help

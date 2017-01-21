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

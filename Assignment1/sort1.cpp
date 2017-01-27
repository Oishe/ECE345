// Name: Oishe Farhan
// Date 17-01-2017
// Title: quicksort

#include <stdio.h>
#include <time.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sys/time.h>
typedef unsigned long long timestamp_t;

using namespace std;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

//struct for storing reddit submissions
struct Submission{
  int votes; //sorting key
  string rest;
};

void printArrayAsCSV(vector<Submission>& array){
  for (int i=0; i<array.size(); i++){
    cout << array[i].votes;
    cout << array[i].rest << endl;
  }
}

Submission lineToObject( string line){
  //Fill Submission struct from one line from CSV
  Submission newSubmission;
  //replace all ',' with ' ' for easy stringstream capture
  // replace(line.begin(), line.end(), ',', ' ');
  //caputre full line to a stringstream
  istringstream ss(line);
  //store values into the structure
  ss >> newSubmission.votes;
  ss >> newSubmission.rest;
  return newSubmission;
}

vector<Submission> parser(char const *filename[]){
  //Open input file produced by command line argument
  ifstream csvfile;
  csvfile.open(filename[1], ifstream::in);
  //Initialize new vector of objects
  vector<Submission> array;
  //read one line at a time
  string line;
  while(getline(csvfile,line,'\n')){
    array.push_back(lineToObject(line));
  }
  csvfile.close();
  return array;
}

void arraySubmissionSwap(vector<Submission>& array, int index1, int index2){
  Submission temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

int partition (vector<Submission>& array, int L, int R){
  Submission * pivot = &array[R];
  int i = L-1;
  for(int j=L; j<R; j++){
    if(array[j].votes <= pivot->votes){
      i++;
      arraySubmissionSwap(array, i, j);
    }
  }
  i++;
  arraySubmissionSwap(array, i, R);
  return i;
}

void quicksort(vector<Submission>& array, int L, int R){
  //quicksort recursive method
  //P=pivot L=left R=right
  if (L<R){
    int P = partition(array,L,R);
    quicksort(array,L,P-1);
    quicksort(array,P+1,R);
  }

}


int main(int argc, char const *argv[]) {
  //Initialize a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = parser(argv);
  // cout << "unsorted:"<<endl;
  // printArrayAsCSV(array);
  timestamp_t t0 = get_timestamp();
  // Process
  quicksort(array, 0, array.size()-1);
  timestamp_t t1 = get_timestamp();
  double secs = (t1 - t0) / 1000000.0L;
  // cout << "sorted:"<<endl;
  printArrayAsCSV(array);
  // cout << "quicksort time:" << secs<< endl;
  return 0;
}

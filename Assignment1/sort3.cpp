// Name: Vijay Venkatesan
// Date 23-01-2017
// Title: Merge Sort

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

void merge(vector<Submission>& values, int start, int mid, int end){
  int a = mid - start + 1;
  int b = end - mid;
  vector<Submission> temp1, temp2;

  // Populate the temp arrays
  for(int i = 0; i < a; i++){
    temp1.push_back(values[start + i]);
  }
  for(int i = 0; i < b; i++){
    temp2.push_back(values[mid + i + 1]);
  }

  int i = 0, j = 0, k = start;
  // Sort the temp arrays into the original array
  while(i < a && j < b){

    if(temp1[i].votes <= temp2[j].votes){
      values[k] = temp1[i];
      i++;
    }

    else{
      values[k] = temp2[j];
      j++;
    }

    k++;
  }

  // Put leftover values in temp1 and temp2 into original aray
  while(i < a){
    values[k] = temp1[i];
    k++;
    i++;
  }

  while(j < b){
    values[k] = temp2[j];
    k++;
    j++;
  }
}

void mergeSort(vector<Submission>& values, int start, int end){
  if(start < end){
    int mid = (start + end) / 2;

    // Call mergeSort on the two halves of the array
    mergeSort(values, start, mid);
    mergeSort(values, mid + 1, end);

    // Put the two halves of the array back together in order
    merge(values, start, mid, end);
  }
}


int main(int argc, char const *argv[]) {
  //Initialize a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = parser(argv);
  // cout << "unsorted:"<<endl;
  // printArrayAsCSV(array);
  // Sort the values
  timestamp_t t0 = get_timestamp();
  // Process
  mergeSort(array, 0, array.size()-1);
  timestamp_t t1 = get_timestamp();
  double secs = (t1 - t0) / 1000000.0L;
  // cout << "sorted:"<<endl;
  printArrayAsCSV(array);
  // cout << "mergeSort time:" << secs<< endl;
  return 0;
}

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

using namespace std;

//struct for storing reddit submissions
struct Submission{
  int votes; //sorting key
  int unixtime;
  string rawtime;
  string reddit_id;
  int upvotes;
  string subreddit;
  int downvotes;
  int local_time;
  int score;
  int number_comments;
  string  username;
};

void printArrayAsCSV(vector<Submission>& array){
  for (int i=0; i<array.size(); i++){
    cout << array[i].votes << ",";
    cout << array[i].unixtime << ",";
    cout << array[i].rawtime << ",";
    cout << array[i].reddit_id << ",";
    cout << array[i].upvotes << ",";
    cout << array[i].subreddit << ",";
    cout << array[i].downvotes << ",";
    cout << array[i].local_time << ",";
    cout << array[i].score << ",";
    cout << array[i].number_comments << ",";
    cout << array[i].username << endl;
  }
}

Submission lineToObject( string line){
  //Fill Submission struct from one line from CSV
  Submission newSubmission;
  //replace all ',' with ' ' for easy stringstream capture
  replace(line.begin(), line.end(), ',', ' ');
  //caputre full line to a stringstream
  istringstream ss(line);
  //store values into the structure
  ss >> newSubmission.votes;
  ss >> newSubmission.unixtime;
  ss >> newSubmission.rawtime;
  ss >> newSubmission.reddit_id;
  ss >> newSubmission.upvotes;
  ss >> newSubmission.subreddit;
  ss >> newSubmission.downvotes;
  ss >> newSubmission.local_time;
  ss >> newSubmission.score;
  ss >> newSubmission.number_comments;
  ss >> newSubmission.username;
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

/*

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

*/

int main(int argc, char const *argv[]) {
  //Initialize a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = parser(argv);
  cout << "unsorted:"<<endl;
  printArrayAsCSV(array);
  // Sort the values
  mergeSort(array, 0, array.size()-1);
  cout << "sorted:"<<endl;
  printArrayAsCSV(array);
  return 0;
}
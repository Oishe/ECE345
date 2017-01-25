// Name: Hiba Durvesh
// Date 23 Jan, 2017
// Title: Bubble Sort Implementation
// Learned about bubble sort from tutorials point and CS50 on youtube
// Code optimization taken from tutorials point and video

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
    /*cout << array[i].unixtime << ",";
    cout << array[i].rawtime << ",";
    cout << array[i].reddit_id << ",";
    cout << array[i].upvotes << ",";
    cout << array[i].subreddit << ",";
    cout << array[i].downvotes << ",";
    cout << array[i].local_time << ",";
    cout << array[i].score << ",";
    cout << array[i].number_comments << ",";
    cout << array[i].username << endl;*/
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


void bubbleSort(vector<Submission>& array, int arraySize){
	bool swapped = false;
	for (int i=0; i < arraySize; i++){
		swapped = false;
		// After ith iteration last ith elements are in sorted 
		// order so don't compare them
		for (int j=0; j < arraySize-i; j++){
			// Compare elements adjacent to current
			// If smaller swap elements to get ascending order
			if (array[j].votes > array[j+1].votes){
				int temp = array[j].votes;
				array[j].votes = array[j+1].votes;
				array[j+1].votes = temp;
				swapped = true;
			}
		}
		
		// No number was swapped so array is sorted
		if (swapped == false){
			break;
		}
	}
}


int main(int argc, char const *argv[]) {
  //Initialize a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = parser(argv);
  cout << "unsorted:"<<endl;
  printArrayAsCSV(array);
  bubbleSort(array, array.size()-1);
  cout << "sorted:"<< endl;
  printArrayAsCSV(array);
  return 0;
}

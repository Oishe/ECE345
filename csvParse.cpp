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

vector<Submission> createSubmissionVector(ifstream& csvfile)
{
  //Initialize new vector of objects
  vector<Submission> array;
  string line;
  //read one line at a time
  while(getline(csvfile,line,'\n')){
      array.push_back(lineToObject(line));
  }
  return array;
}

void printArrayAsCSV(vector<Submission> array){
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

int main(int argc, char const *argv[]) {
  //Open input file produced by command line argument
  ifstream csvfile;
  csvfile.open(argv[1], ifstream::in);
  //Initialize a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = createSubmissionVector(csvfile);
  printArrayAsCSV(array);
  csvfile.close();
  return 0;
}

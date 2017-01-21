#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
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

Submission lineToObject(const string line){
  //Fill Submission struct from one line from CSV
  Submission newSubmission;
  //caputre full line to a stringstream
  istringstream ss(line);
  //seperate string and int tokens
  string s_token;
  int i_token;
  //store values into the structure
  getline(ss, i_token, ',');
  newSubmission.votes = i_token;
  getline(ss, i_token, ',');
  newSubmission.unixtime = i_token;
  getline(ss, s_token, ',');
  newSubmission.rawtime = s_token;
  getline(ss, s_token, ',');
  newSubmission.reddit_id = s_token;
  getline(ss, i_token, ',');
  newSubmission.upvotes = i_token;
  getline(ss, s_token, ',');
  newSubmission.subreddit = s_token;
  getline(ss, i_token, ',');
  newSubmission.downvotes = i_token;
  getline(ss, i_token, ',');
  newSubmission.local_time = i_token;
  getline(ss, i_token, ',');
  newSubmission.score = i_token;
  getline(ss, i_token, ',');
  newSubmission.number_comments = i_token;
  getline(ss, s_token, ',');
  newSubmission.username = s_token;
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

int main(int argc, char const *argv[]) {
  //Open input file produced by command line argument
  ifstream csvfile;
  csvfile.open(argv[1], ifstream::in);
  //Initialized a vector of structs
  //and parse through lines to fill it
  vector<Submission> array = createSubmissionVector(csvfile);
  int num_entries = array.size();
  //sorting
  csvfile.close();
  return 0;
}

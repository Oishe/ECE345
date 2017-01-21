#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

struct 

vector<int> getLineToVector(istream& str)
{
    vector<int> result;
    string line;
    getline(str,line);

    stringstream lineStream(line);
    string cell;

    // while(getline(lineStream,cell, ','))
    // {
    //     result.push_back(stoi(cell));
    // }
    // // This checks for a trailing comma with no data after it.
    // if (!lineStream && cell.empty())
    // {
    //     // If there was a trailing comma then add an empty element.
    //     result.push_back("");
    // }
    return result;
}

int main(int argc, char const *argv[]) {
  ifstream csvfile;
  csvfile.open(argv[1], ifstream::in);
  char c = csvfile.get();
  while (csvfile.good()) {
    cout << c;
    c = csvfile.get();
  }
  csvfile.close();
  return 0;
}

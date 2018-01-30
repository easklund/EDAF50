#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"
using namespace std;
using std::cout;
using std::endl;

string decode_string(string s)
{
  for(auto& c : s) {
      c = decode(c);
  }
  return s;
}

int main(int argc, char** argv)
{
  cout << argc << endl;
  string line;
  ifstream myfile (argv[1]);
  ofstream dec ("FILENAME.txt");
  if (myfile.is_open() && dec.is_open()){
    while ( getline (myfile,line) )
    {
      dec << decode_string(line);
    }
    myfile.close();
    dec.close();
  }
  else cout << "Unable to open file";

  return 0;
}

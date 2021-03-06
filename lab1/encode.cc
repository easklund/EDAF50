#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"
using namespace std;
using std::cout;
using std::endl;

string encode_string(string s)
{
  for(auto& c : s) {
      c = encode(c);
  }
  return s;
}

int main(int argc, char** argv)
{
  cout << argc << endl;
  string line;
  ifstream myfile (argv[1]);
  ofstream enc ("enc.txt");
  if (myfile.is_open() && enc.is_open()){
    while ( getline (myfile,line) )
    {
      enc << encode_string(line);
    }
    myfile.close(); // behövs inte, string gör det själv när man stänger ner programmet
    enc.close();
  }
  else cout << "Unable to open file";

  return 0;
}

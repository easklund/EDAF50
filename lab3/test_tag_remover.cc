#include <string>
#include <iostream>
#include <fstream>
#include "tagRemover.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

void testTagRemove() {
  string test = "en tag: <första>funkar en andra tag? <andra\n>Specialtecken? &lt&nbsp&amp&gt";
  string right = "en tag: funkar en andra tag? Specialtecken? < &>";
  TagRemover tr(test);
  string testRemoved = tr.getText();
  if (testRemoved == right)
    cout << "<<TagRemover worked>>" << endl;
  else
    cout << "<<TagRemover failed>>" << endl;
  cout  << testRemoved << endl;
}

void testHtmlFile(){
  ifstream in("test.html");
  std::streambuf *cinbuf = std::cin.rdbuf();
  std::cin.rdbuf(in.rdbuf()); //redirect file to cin
  cout << endl << "'Fixed' test.html:" << endl;
  TagRemover tr(cin);
  tr.print(cout);
}

int main() {
  testTagRemove();
  testHtmlFile();
  return 0;
}

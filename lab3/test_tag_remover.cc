#include <string>
#include <iostream>
#include "tagRemover.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

void testTagRemove() {
  string test = "en Tag: <första>funkar en till:<andra>&lt&nbsp&amp&gt";
  string right = "en Tag: första funkar en till: andra";
  //cin >> test;
  TagRemover tr(test);
  string testRemoved = tr.getText();
  if (testRemoved == right)
    cout << "TagRemover worked" << endl;
  else
    cout << "TagRemover failed" << endl;
  cout << testRemoved << endl;
}

int main() {
  testTagRemove();
  return 0;
}

#include "tagRemover.h"

using std::string;
using std::cout;
using std::endl;

void testTagRemove() {
  string test = "en Tag: <första> funkar en till: <andra>";
  string right = "en Tag: första funkar en till: andra";

  TagRemover tr(test);
  string testRemoved = tr.getText();
  if (testRemoved == right)
    cout << "TagRemover worked" << endl;
  else
    cout << "TagRemover failed" << endl;
  tr.print(cout);
}

int main() {
  testTagRemove();
}

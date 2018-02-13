#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class TagRemover {
public:
	TagRemover(istream& is);
	TagRemover(const string& s);
	void print(ostream& os);
  	string getText() const;
private:
  string withHtml;
  string noHtml;
  void removeHtml();
  void fixSpecialChars();
};

#endif

#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <string>

using std::string;

class TagRemover {
public:
	TagRemover(const string& s);
	int print(const string s) const;
  string getText() const;
private:
  string withHtml;
  string noHtml;
  void remove(const string& s);
};

#endif

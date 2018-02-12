#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover {
public:
	TagRemover(const string& s);
	int print() const;
  string TagRemover::getText() const;
private:
  string withHtml;
  string noHtml;
  void TagRemover::remove(const string& s);
};

#endif

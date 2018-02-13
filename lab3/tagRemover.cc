#include "tagRemover.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
using std::regex;

TagRemover::TagRemover(istream& is){
	string line;
	while(getline(is, line)){
		noHtml += line + "\n";
	}
	removeHtml();
	fixSpecialChars();
}

TagRemover::TagRemover(const string& s){
	noHtml = s;
	removeHtml();
	fixSpecialChars();
}

string TagRemover::getText() const {
  	return noHtml;
}

void TagRemover::print(ostream& os){
	os << noHtml;
}

void TagRemover::removeHtml(){
	regex tags("<[^<]*>");
	noHtml = regex_replace(noHtml, tags, "");
}

void TagRemover::fixSpecialChars(){
	regex tagslt("&lt*");
	noHtml = regex_replace(noHtml, tagslt, "<");
	regex tagsgt("&gt*");
	noHtml = regex_replace(noHtml, tagsgt, ">");
	regex tagsnbsp("&nbsp*");
	noHtml = regex_replace(noHtml, tagsnbsp, " ");
	regex tagsamp("&amp*");
	noHtml = regex_replace(noHtml, tagsamp, "&");
}

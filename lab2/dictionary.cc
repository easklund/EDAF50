#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::unordered_set;
using std::ifstream;
using std::cout;

unordered_set<string> words;

Dictionary::Dictionary() {
	words = unordered_set<string>();
	ifstream infile("words.txt");
	string wordline;
	for(string line; getline(infile, line);){
		wordline = line.substr(0, line.find(" "));
		words.insert(wordline);
	}
}

bool Dictionary::contains(const string& word) const {
	if(words.count(word) > 0){
		return true;
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

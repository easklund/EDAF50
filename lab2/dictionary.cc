#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::unordered_set;
using std::ifstream;
using std::cout;
using std::stringstream;

Dictionary::Dictionary() {
	words_set = unordered_set<string>();
	ifstream infile("words.txt");
	for(string line; getline(infile, line);){
		string wordline;
		string word;
		vector<string> trigrams;
		stringstream ss(line);
		ss >> wordline;
		word = wordline;
		words_set.insert(wordline);
		ss >> wordline;
		while(ss >> wordline){
			trigrams.push_back(wordline);
		}
		words[word.length()].push_back(Word(word, trigrams));
	}
}

bool Dictionary::contains(const string& word) const {
	if(words_set.count(word) > 0){
		return true;
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	// add_trigram_suggestions(suggestions, word);
	// rank_suggestions(suggestions, word);
	// trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string>& suggestions, std::string& word) const {
	int length = word.length();
	int stay = (word.length() - 2) / 2;
	if(length > 2){
		for(int i = length - 2; i < length + 1; i++){
			for(int j = 0; j < words[i].size(); j++){
				Word w = words[i][j];
				if(w.get_matches(word.) >= stay){
					suggestions.push_back(w.get_word());
				}
			}
		}
	}
}

void Dictionary::rank_suggestions(std::vector<std::string>& suggestions, std::string& word) const {

}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const {

}

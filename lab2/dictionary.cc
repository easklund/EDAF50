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
		words_set.insert(word);
		ss >> wordline;
		while(ss >> wordline){
			//cout << wordline << " ";
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
	add_trigram_suggestions(suggestions, word);
	// rank_suggestions(suggestions, word);
	// trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(std::vector<std::string>& suggestions, const string& word) const {
	int length = word.length();
	unsigned int stay = (word.length() - 2) / 2;
	if(length > 2){
		vector<string> trigrams (length-2);
		for(int i = 0; i < length-2; i++){
			stringstream temptri;
			temptri << word.at(i) << word.at(i+1) << word.at(i+2);
			trigrams[i] = temptri.str();
			cout << " " << temptri.str();
		}
		sort(trigrams.begin(), trigrams.end());
		for(int i = length - 1; i <= length + 1; i++){
			for(Word w: words[i]){
				if(w.get_matches(trigrams) >= stay){
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

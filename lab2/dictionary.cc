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
using std::pair;
using std::min;

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
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
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

void Dictionary::rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const {
	vector<pair<int, string>> sugg_pairs;
	// for each string i suggestion
	for(string s: suggestions){
		// räkna ut "edit-distance" till word
		int tracker, temp;
		int d[26][26];
		int m = word.length();
		int n = s.length();

		for(int i = 0; i <= m; i++){
			d[0][i] = i;
		}
		for(int j = 0; j <= n; j++){
			d[j][0] = j;
		}

		for (int j=1;j<=m;j++) {
      	 	for(int i=1;i<=n;i++) {
            	if(s[i-1] == word[j-1]) {
                	tracker = 0;
            	} else {
                	tracker = 1;
            	}
            	temp = min((d[i-1][j]+1),(d[i][j-1]+1));
           		d[i][j] = min(temp,(d[i-1][j-1]+tracker));
       		}
    	}
    	sugg_pairs.push_back(make_pair(d[n][m], s));
	}
	// sortera sugg_pairs
	sort(sugg_pairs.begin(), sugg_pairs.end());
	// cleara suggestions
	suggestions.clear();
	// lägg in strängarna i suggestions igen
	for(auto p: sugg_pairs){
		suggestions.push_back(p.second);
	}

}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const {
	if (suggestions.size() > 5) {
		suggestions.resize(5);
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
	
	ifstream infile("unprocessed-words.txt");
	ofstream outfile("words.txt");
	
	for(string line; getline(infile, line);){
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		outfile << line;
		if(line.size() >= 3){
			outfile << " " << line.size()-2;
			vector<string> trigrams (line.size()-2);
			for(unsigned int i = 0; i < line.size()-2; i++){
			stringstream temptri;
			temptri << line.at(i) << line.at(i+1) << line.at(i+2);
			trigrams[i] = temptri.str();
			}
			sort(trigrams.begin(), trigrams.end());
			for(string &s : trigrams){
				outfile << " " << s;
			}
		}
		outfile << endl;
	}
	return 0;
}
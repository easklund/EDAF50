#ifndef PRIME_H
#define PRIME_H

#include <string>

using std::string;

class Prime {

public:
	string primesUnderN(const int n);
	int largestPrimeUnderN(const int n);
	string getPrimeLetters();
private:
	string primeLetters; //string with example CCPPPPCCCCPPCPCP
};

#endif
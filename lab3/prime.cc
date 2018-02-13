#include "prime.h"
#include <string>
#include <iostream>
#include <sstream>

using std::endl;
using std::cout;
using std::string;
using std::stringstream;

string Prime::primesUnderN(const int n){
	string primes = "";
	string primeLetters = string(n+1, 'P');
	primeLetters[0] = 'C';
	primeLetters[1] = 'C';
	for(int i = 2; i <= n; i++){
		primeLetters[i] = 'P';
	}
	for(int p = 2; p*p< n; p ++){
		if(primeLetters[p] == 'P'){
			for(int i = p*2; i <= n; i += p){
				primeLetters[i] = 'C';
			}
		}
	}
	stringstream ss;
	for(int p = 2; p<=n; p++){
		if(primeLetters[p] == 'P'){
			ss << p << " ";		
		}
	}

	cout << primeLetters << endl;

	cout << ss.str() << endl;
	primes = ss.str();
	return primes;
}

string Prime::largestPrimeUnderN(const int n){
	string primes, primeLetters;
	for(int i = 0; i < n; i++){
		primeLetters[i] = 'P';
	}


	return primes;
}
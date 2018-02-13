#include "prime.h"
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;

string Prime::primesUnderN(const int n){
	string primes = "";
	string primeLetters = string(n-1, 'P');
	primeLetters[0] = 'C';
	primeLetters[1] = 'C';
	for(int i = 2; i <= n; i++){
		primeLetters[i] = 'P';
	}
	for(int p = 2; p < n; p++){
		if(primeLetters[p] == 'P'){
			for(int i = p*2; i < n; i += p){
				primeLetters[i] = 'C';
			}
		}
	}

	cout << primeLetters << endl;


	return primes;
}

string Prime::largestPrimeUnderN(const int n){
	string primes, primeLetters;
	for(int i = 0; i < n; i++){
		primeLetters[i] = 'P';
	}


	return primes;
}
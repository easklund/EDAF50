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
	primeLetters = string(n+1, 'P'); //populate string

	findPrimes(n);
	stringstream ss;
	for(int p = 2; p<=n; p++){ //gets all primes
		if(primeLetters[p] == 'P'){
			ss << p << " ";		
		}
	}

	primes = ss.str();
	return primes;
}

int Prime::largestPrimeUnderN(const int n){
	primeLetters = string(n+1, 'P'); //populate string
	
	findPrimes(n);

	int prime = primeLetters.rfind('P');
	return prime;
}

string Prime::getPrimeLetters(){
	return primeLetters;
}

void Prime::findPrimes(const int n){
	primeLetters[0] = 'C';
	primeLetters[1] = 'C';

	for(int p = 2; p*p< n; p ++){
		if(primeLetters[p] == 'P'){
			for(int i = p*2; i <= n; i += p){
				primeLetters[i] = 'C';
			}
		}
	}
}


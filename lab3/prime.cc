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
	primeLetters = string(n+1, 'P');
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
	
	primes = ss.str();
	return primes;
}

int Prime::largestPrimeUnderN(const int n){
	int prime;
	primeLetters = string(n+1, 'P');
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
	for(int p = 2; p<=n; p++){
		if(primeLetters[p] == 'P'){
			prime = p;	
		}
	}

	return prime;
}

string Prime::getPrimeLetters(){
	return primeLetters;
}
#include "prime.h"
#include <iostream>

using std::cout;
using std::endl;


void testStringSequence(Prime p){
	string results = p.primesUnderN(20);
	string letters = p.getPrimeLetters();
	string expectedLetters = "CCPPCPCPCCCPCPCCCPCPC";
	if(letters == expectedLetters){
		cout << "testStringSequence Passed" << endl;
	} else {
		cout << "testStringSequence Failed" << endl;
	}
}

void testPrintAllPrimes(Prime p){
	string results = p.primesUnderN(35);
	string expectedResults = "2 3 5 7 11 13 17 19 23 29 31 ";
	if(results == expectedResults){
		cout << "testPrintAllPrimes Passed" << endl;
	} else {
		cout << "testPrintAllPrimes Failed" << endl;
	}
}

void testPrintLargestPrime5000(Prime p){
	int result = p.largestPrimeUnderN(5000);
	int expectedResults = 4999;
	if(result == expectedResults){
		cout << "testPrintLargestPrime5000 Passed" << endl;
	} else {
		cout << "testPrintLargestPrime5000 Failed" << endl;
	}

}

void testPrintLargestPrime100000(Prime p){
	int result = p.largestPrimeUnderN(100000);
		int expectedResults = 99991;
	if(result == expectedResults){
		cout << "testPrintLargestPrime100000 Passed" << endl;
	} else {
		cout << "testPrintLargestPrime100000 Failed" << endl;
	}

}

int main(){
	Prime p = Prime();
	testStringSequence(p);
	testPrintAllPrimes(p);
	testPrintLargestPrime5000(p);
	testPrintLargestPrime100000(p);
}
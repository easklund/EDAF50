#include "prime.h"
#include <iostream>

using std::cout;

int main(){
	Prime p = Prime();
	string results = p.primesUnderN(200);
	cout << results;
}
#include <iostream>
#include <sstream>
#include "date.h"

using std::ostringstream;
using std::istringstream;
using std::string;
using std::endl;
using std::cout;

template <class T>
string toString(T& t){
	ostringstream oss;
	oss << t;
	return oss.str();
}

template <class T>
T stringCast(string& s){
	istringstream iss(s);
	T t;
	iss >> t;
	return t;
}

void testDoubleToString(){
	double d = 1.222;
	string test = toString(d);
	string correct = "1.222";
	if (test == correct){
		cout << "testDoubleToString Passed" << endl;
	} else {
		cout << "testDoubleToString Failed" << endl;
	}
}

void testIntToString(){
	int i = 1337;
	string test = toString(i);
	string correct = "1337";
	if (test == correct){
		cout << "testIntToString Passed" << endl;
	} else {
		cout << "testIntToString Failed" << endl;
	}
}

void testDateToString(){
	Date d = Date(1994, 03, 31);
	string test = toString(d);
	string correct = "1994-03-31";
	if (test == correct){
		cout << "testDateToString Passed" << endl;
	} else {
		cout << "testDateToString Failed" << endl;
	}
}

void testStringToDouble(){
	string test = "1.222";
	double d = stringCast<double>(test);
	double correct = 1.222;
	if(d == correct){
		cout << "testStringToDouble Passed" << endl;
	} else {
		cout << "testStringToDouble Failed" << endl;
	}
}

void testStringToInt(){
	string test = "1337";
	int d = stringCast<int>(test);
	int correct = 1337;
	if(d == correct){
		cout << "testStringToInt Passed" << endl;
	} else {
		cout << "testStringToInt Failed" << endl;
	}
}

//Detta testet antar att toString funkar
void testStringToDate(){
	string test = "1994-03-31";
	Date d = stringCast<Date>(test);
	string correct = toString(d);
	if(test == correct){
		cout << "testStringToDate Passed" << endl;
	} else {
		cout << "testStringToDate Failed" << endl;
	}
}

int main(){
	testDoubleToString();
	testIntToString();
	testDateToString();
	testStringToDouble();
	testStringToInt();
	testStringToDate();
	return 0;
}
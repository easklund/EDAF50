#include <ctime>  // time and localtime
#include <ios>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "date.h"

using std::ostream;
using std::istream;
using std::setw;
using std::setfill;
using std::cout;
using std::stoi;
using std::string;
using std::ios_base;
using std::endl;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day +=1;
	if (day > daysPerMonth[month-1]){
		day = 1;
		month += 1;
	}
	if(month > 12){
		month = 1;
		day = 1;
		year ++;
	}
}

ostream& operator<<(ostream& os, Date& d){
	os << setw(4) << setfill('0') << d.getYear() << '-';
	os << setw(2) << setfill('0') << d.getMonth() << '-';
	os << setw(2) << setfill('0') << d.getDay();
	return os;
}

istream& operator>>(istream& is, Date& d){
	string line;
	getline(is, line);
	int count = std::count(line.begin(), line.end(), '-');
	if(count == 2){
		string year = line.substr(0, 4);
		string month = line.substr(5, 2);
		string day = line.substr(8);
		if(year.find('-') != string::npos){ // Kolla att år är korrekt
			is.setstate (ios_base::failbit);
			return is;
		}
		d.year = stoi(year);
		if((month.find('-') != string::npos) || (stoi(month) > 12)){ //Kolla månad
			is.setstate (ios_base::failbit);
			return is;
		}
		d.month = stoi(month);
		if(month.find('-') != string::npos || stoi(day) > Date::daysPerMonth[d.month-1]){ //Kolla dag
			is.setstate (ios_base::failbit);
			return is;
		}
		d.day = stoi(day);
	} else{
		cout << "Wrong format, expected XXXX-XX-XX" << endl;
		is.setstate (ios_base::failbit);
		return is;
	}
	return is; //to get rid of warning
}



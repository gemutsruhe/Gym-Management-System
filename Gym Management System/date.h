#pragma once
#include <string>
using namespace std;

class date {
private:
	int year;
	int month;
	int day;
	int period;
public:
	//date();
	date(string, int);
	string getMembershipStart();
	string getMembershipEnd();
	int getRemainDay();
	void extendPeriod(int);
};

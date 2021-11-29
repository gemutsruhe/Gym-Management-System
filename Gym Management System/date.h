#pragma once
#include <string>

class date {
private:
	int year;
	int month;
	int day;
	int period;
public:
	//date();
	date(std::string, int);
	std::string getMembershipStart();
	std::string getMembershipEnd();
	int getRemainDay();
	void extendPeriod(int);
};

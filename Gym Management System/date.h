#pragma once
#include <string>

class date {
private:
	std::string year;
	std::string month;
	std::string day;
	int period;
public:
	date(std::string, int);
	std::string getMembershipStart();
	std::string getMembershipEnd();
	int getRemainDay();
	void extendPeriod(int);
	int getPeriod();
};

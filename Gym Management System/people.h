#pragma once
#include <string>

class people {
protected:
	std::string name;
	std::string phone_num;
public:
	std::string getName();
	std::string getPhone_num();
	virtual std::string dataToString();
	virtual people *parseString(std::string);
};
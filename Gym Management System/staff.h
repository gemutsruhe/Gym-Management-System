#pragma once
#include "people.h"

class staff : public people {
protected:
	int salary;
public:
	staff();
	staff(std::string, std::string, int);
	virtual std::string dataToString();
	virtual people *parseString(std::string);
};

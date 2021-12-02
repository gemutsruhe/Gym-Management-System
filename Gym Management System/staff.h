#pragma once
#include "people.h"

class staff : public people {
protected:
	int salary;
public:
	virtual std::string dataToString();
	virtual people *parseString(std::string);
};

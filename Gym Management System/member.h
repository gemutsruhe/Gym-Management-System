#pragma once
#include "people.h"
#include "date.h"

class member : public people {
protected:
	std::string id;
	date *membership;
	int lockerNum;
public:
	member();
	member(std::string, std::string, std::string, std::string, int, int);
	void extendMembership(int);
	void changeLocker(int);
	virtual std::string toFile();
};

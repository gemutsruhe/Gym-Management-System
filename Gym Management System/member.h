#pragma once
#include "people.h"
#include "date.h"

class member : public people {
protected:
	string id;
	date *membership;
	int lockerNum;
public:
	member();
	member(string, string, string, string, int, int);
	void extendMembership(int);
	void changeLocker(int);
	string toFile();
};

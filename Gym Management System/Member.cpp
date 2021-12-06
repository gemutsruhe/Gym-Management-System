#include "member.h"
#include "date.h"

member::member() {
	this->id = "";
	this->name = "";
	this->phone_num = "";
	this->membership = new date("1900-01-01", 0);
	this->lockerNum = 0;
}

member::member(std::string id, std::string name, std::string phone_num, std::string membership_start, int period, int lockerNum) {
	this->id = id;
	this->name = name;
	this->phone_num = phone_num;
	this->membership = new date(membership_start, period);
	this->lockerNum = lockerNum;
}
void member::extendMembership(int month) {
	this->membership->extendPeriod(month);
}

void member::changeLocker(int lockerNum) {
	this->lockerNum = lockerNum;
}

std::string member::dataToString() {
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(membership->getPeriod()) + " " + std::to_string(lockerNum);
}

people *member::parseString(std::string dataString) {
	int substrStart = 0;
	std::vector<std::string> split = (new people())->split(dataString, ' ');
	return new member(split[0], split[1], split[2], split[3], std::stoi(split[4]),std::stoi(split[5]));
}

date *member::getMembership(){
	return membership;
}

int member::getLockerNum() {
	return lockerNum;
}
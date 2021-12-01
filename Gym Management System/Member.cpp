#include "member.h"
#include "date.h"

member::member() {
	this->id = "";
	this->name = "";
	this->phone_num = "";
	this->membership = new date("", 0);
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
	this->membership;
}

void member::changeLocker(int lockerNum) {
	this->lockerNum = lockerNum;
}

std::string member::toFile() {
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(lockerNum);
}

std::string member::getID(){
	return id;
}

date *member::getMembership(){
	return membership;
}
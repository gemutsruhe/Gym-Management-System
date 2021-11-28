#include "People.h"

People::People(string name, string phone_num) {
	this->name = name;
	this->phone_num = phone_num;
}


Member::Member(string id, string name, string phone_num, string membership_start, int period, int lockerNum) {
	this->id = id;
	this-name = name;
	this->phone_num = phone_num;
	this->membership_start = membership_start;
	membership_start.split("-");
	this->lockerNum = lockerNum;
}
void Member::extendMembership(int month){
	this->membership
}



void Trainer::addPTMember(PTMember *newMember){
	this->chargePTMember.push_back(*newMember);
}
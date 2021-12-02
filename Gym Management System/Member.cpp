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

virtual std::string member::dataToString() {
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(membership->getPeriod()) + " " + std::to_string(lockerNum);
}

virtual member *parseString(std::string dataString){
	int substrStart = 0;
	vector<std::string> split;
	for(int i = 0; i < dataString.size(); i++){
		if(dataString[i] == " "){
			split.push_back(dataString.substr(substrStart,i - substrStart));
			i = substrStart;
		}
	}
	return new member(split[0],split[1],split[2],split[3],Integer.parseInt(split[4]),Integer.parseInt(split[5]));
}

std::string member::getID(){
	return id;
}

date *member::getMembership(){
	return membership;
}
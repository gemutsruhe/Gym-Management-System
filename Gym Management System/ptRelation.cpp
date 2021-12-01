#include "ptRelation.h"

void trainer::addPTMember(ptMember* newMember) {
	this->chargePTMember.push_back(newMember);
}

void trainer::deletePTMember(std::string id) {
	for (int i = 0; i < chargePTMember.size(); i++) {
		if (chargePTMember[i]->getID() == id) {
			chargePTMember.erase(chargePTMember.begin() + i);
			break;
		}
	}
}

ptMember::ptMember(member *convertMember, std::string trainerID, int ptNum, health *measure) {
	this->id = convertMember->getID();
	this->name = convertMember->getName();
	this->phone_num = convertMember->getPhone_num();
	this->membership = convertMember->getMembership();
	this->remainPT = ptNum;
	this->trainerID = trainerID;
	this->healthData.push_back(*measure);
}

std::string ptMember::toFile() {
	std::string trainedDateStr = "";
	int i;
	for (i = 0; i < trainedDate.size() - 1; i++) trainedDateStr += trainedDate[i] + ",";
	trainedDateStr += trainedDate[i];
	std::string healthDataStr = "";
	for(i = 0; i < healthData.size() - 1; i++) healthDataStr += healthData[i].toString() + ",";
	healthDataStr += healthData[i].toString();
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(lockerNum) + " " + trainerID + " " + std::to_string(remainPT) + " " + trainedDateStr + " " + healthDataStr;
}

void ptMember::addNewHealth(health *recentData) {
	healthData.push_back(*recentData);
}
void ptMember::changeTrainer(std::string trainerID){
	this->trainerID = trainerID;
}
void addTrainedDate(std::string);
void extendPT(int);

std::string ptMember::getID() {
	return id;
}

trainer::trainer(std::string name, std::string phone_num, int salary){
	this->name = name;
	this->phone_num = phone_num;
	this->salary = salary;
	this->chargePTMember;
}

std::string trainer::toFile() {
	return "";
}
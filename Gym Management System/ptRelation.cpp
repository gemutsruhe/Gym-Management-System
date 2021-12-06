#include "ptRelation.h"

ptMember::ptMember() {

}

ptMember::ptMember(member *convertMember, std::string trainerID, int ptNum, health *measure) {
	this->id = convertMember->getID();
	this->name = convertMember->getName();
	this->phone_num = convertMember->getPhone_num();
	this->membership = convertMember->getMembership();
	this->lockerNum = convertMember->getLockerNum();
	this->remainPT = ptNum;
	this->trainedDate = *(new std::vector<std::string>());
	this->trainerID = trainerID;
	this->healthData.push_back(measure);
}

ptMember::ptMember(std::string id, std::string name, std::string phone_num, std::string membership_start, int period, int lockerNum, int remainPT, std::vector<std::string> trainedDate, std::string trainerID, std::vector<health *> healthData) {
	this->id = id;
	this->name = name;
	this->phone_num = phone_num;
	this->membership = new date(membership_start, period);
	this->lockerNum = lockerNum;
	this->remainPT = remainPT;
	this->trainedDate = trainedDate;
	this->trainerID = trainerID;
	this->healthData = healthData;
} 

std::string ptMember::trainedDateToString() {
	std::string trainedStr;
	for (int i = 0; i < trainedDate.size(); i++) {
		if (i == trainedDate.size() - 1) {
			trainedStr += trainedDate[i];

			break;
		}
		trainedStr += trainedDate[i] + ",";
	}
	return trainedStr;
}

std::string ptMember::healthDataToString() {
	std::string healthStr;
	for (int i = 0; i < healthData.size(); i++) {
		if (i == healthData.size() - 1) {
			healthStr += healthData[i]->toString();
			break;
		}
		healthStr += healthData[i]->toString() + ",";
	}
	return healthStr;
}

std::string ptMember::dataToString() {
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(membership->getPeriod()) + " " + std::to_string(lockerNum) + " " + std::to_string(remainPT) + " " + trainedDateToString() + " " + trainerID + " " + healthDataToString();
}

people *ptMember::parseString(std::string dataString) {
	int substrStart = 0;
	std::vector<std::string> splitList = (new people())->split(dataString, ' ');
	std::vector<std::string> trainedDateList = (new people())->split(splitList[7], ',');
	std::vector<std::string> healthDataStr = (new people())->split(splitList[9], ',');
	std::vector<health *> healthDataList;
	for (int i = 0; i < healthDataStr.size(); i++) {
		healthDataList.push_back((new health(healthDataStr[i])));
	}
	return new ptMember(splitList[0],splitList[1],splitList[2],splitList[3],std::stoi(splitList[4]),std::stoi(splitList[5]),std::stoi(splitList[6]),trainedDateList,splitList[8],healthDataList);
}

void ptMember::addNewHealth(health *recentData) {
	healthData.push_back(recentData);
}

void ptMember::changeTrainer(std::string trainerID){
	this->trainerID = trainerID;
}

void ptMember::addTrainedDate(std::string trained) {
	trainedDate.push_back(trained);
	remainPT--;
}

void ptMember::extendPT(int ptNum) {
	remainPT += ptNum;
}

std::string ptMember::getID() {
	return id;
}

trainer::trainer() {

}

trainer::trainer(std::string id, std::string name, std::string phone_num, int salary, std::vector<std::string> chargePTMember){
	this->id = id;
	this->name = name;
	this->phone_num = phone_num;
	this->salary = salary;
	this->chargePTMember = chargePTMember;
}

void trainer::addPTMember(std::string memberID) {
	this->chargePTMember.push_back(memberID);
}

void trainer::deletePTMember(std::string id) {
	for (int i = 0; i < chargePTMember.size(); i++) {
		if (chargePTMember[i] == id) {
			chargePTMember.erase(chargePTMember.begin() + i);
			break;
		}
	}
}

std::string trainer::dataToString() {
	std::string ptMemberString;
	int i;
	for (i = 0; i < chargePTMember.size() - 1; i++) {
		ptMemberString += chargePTMember[i] + ",";
	}
	ptMemberString += chargePTMember[i];
	return id + " " + name + " " + phone_num + " " + std::to_string(salary) + " " + ptMemberString;
}

people* trainer::parseString(std::string dataString) {
	std::vector<std::string> split = (new member())->split(dataString, ' ');
	std::vector<std::string> ptMemberList = (new member())->split(split[4], ',');
	return new trainer(split[0], split[1], split[2], std::stoi(split[3]), ptMemberList);
}


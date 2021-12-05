#include "peopleData.h"
#include "ptRelation.h"
#include <fstream>
#include <string>
#include <vector>

peopleData::peopleData() {

}

void peopleData::loadFile(std::string fileName) {
	std::ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
			if (line == "" || line == "\n") break;
			if (fileName == "member.txt") memberList.push_back((new member)->parseString(line));
			else if (fileName == "ptMember.txt") ptMemberList.push_back((new ptMember)->parseString(line));
			else if (fileName == "staff.txt") staffList.push_back((new staff)->parseString(line));
			else if (fileName == "trainer.txt") trainerList.push_back((new trainer)->parseString(line));
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
	}
	file.close();
}

bool peopleData::loadData() {
	loadFile("member.txt");
	loadFile("ptMember.txt");
	loadFile("staff.txt");
	loadFile("trainer.txt");
	return true;
}

bool peopleData::exportData() {
	exportFile("member.txt", memberList);
	exportFile("ptMember.txt", ptMemberList);
	exportFile("staff.txt", staffList);
	exportFile("trainer.txt", trainerList);
	return true;
}

void peopleData::addMember(std::string id, std::string name, std::string phone_num, std::string membership_start, int period, int lockerNum){
	member *newMember = new member(id, name, phone_num, membership_start, period, lockerNum);
	memberList.push_back(newMember);
}

void peopleData::memberToPT(std::string id, std::string trainerID, int ptNum, health *healthData){
	for(int i = 0; i < memberList.size(); i++){
		if((memberList[i])->getID() == id){
			ptMemberList.push_back(new ptMember(((member*)memberList[i]), trainerID, ptNum, healthData));
			memberList.erase(memberList.begin() + i);
			break;
		}
	}
}

void peopleData::addStaff(std::string id, std::string name, std::string phone_num, int salary){
	staffList.push_back(new staff(id, name, phone_num, salary));
}

void peopleData::addTrainer(std::string id, std::string name, std::string phone_num, int salary){
	trainer *newTrainer = new trainer(id, name, phone_num, salary, *(new std::vector<std::string>));
	trainerList.push_back(newTrainer);
}

void peopleData::addHealthData(std::string ptMemberID, health *newHealthData){
	for(int i = 0; i < ptMemberList.size(); i++){
		if((ptMemberList[i])->getID() == ptMemberID){
			((ptMember*)ptMemberList[i])->addNewHealth(newHealthData);
		}
	}
}

void peopleData::addTrainedDate(std::string ptMemberID, std::string trainedDate) {
	for (int i = 0; i < ptMemberList.size(); i++) {
		if ((ptMemberList[i])->getID() == ptMemberID) {
			((ptMember*)ptMemberList[i])->addTrainedDate(trainedDate);
		}
	}
}

void peopleData::exportFile(std::string fileName, std::vector<people *> peopleList) {
	std::ofstream file;
	file.open(fileName, std::ios::out);
	if (file.is_open()) {
		int i;
		for (i = 0; i < peopleList.size(); i++) {
			if (fileName == "member.txt") file << ((member*)peopleList[i])->dataToString() << std::endl;
			else if (fileName == "ptMember.txt") file << ((ptMember*)peopleList[i])->dataToString() << std::endl;
			else if (fileName == "staff.txt") file << ((staff*)peopleList[i])->dataToString() << std::endl;
			else if (fileName == "trainer.txt") file << ((trainer *)peopleList[i])->dataToString() << std::endl;
		}
	}
}

std::vector<std::string> peopleData::getPTMemberData() {
	std::vector<std::string> ptMemberData;
	for (int i = 0; i < ptMemberList.size(); i++) {
		ptMemberData.push_back(((ptMember*)ptMemberList[i])->dataToString());
	}
	return ptMemberData;
}

void peopleData::chargeMember(std::string trainerID, std::string ptMemberID) {
	for (int i = 0; i < trainerList.size(); i++) {
		if (trainerList[i]->getID() == trainerID) ((trainer*)trainerList[i])->addPTMember(ptMemberID);
	}
}

std::string peopleData::getMembershipEnd(std::string id) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i]->getID() == id) return ((member*)memberList[i])->getMembership()->getMembershipEnd();
	}
	for (int i = 0; i < ptMemberList.size(); i++) {
		if (ptMemberList[i]->getID() == id) return ((ptMember*)ptMemberList[i])->getMembership()->getMembershipEnd();
	}
	return "";
}

std::vector<std::string> peopleData::getTrainerData() {
	std::vector<std::string> trainerData;
	for (int i = 0; i < trainerList.size(); i++) {
		trainerData.push_back(((trainer*)trainerList[i])->dataToString());
	}
	return trainerData;
}

void peopleData::transferMembership(std::string prevID, std::string id, std::string name, std::string phoneNum, int lockerNum) {
	for (int i = 0; i < memberList.size(); i++) {
		if(memberList[i]->getID() == prevID) {
			date *membershipDate = ((member*)memberList[i])->getMembership();
			memberList.push_back(new member(id, name, phoneNum, membershipDate->getMembershipStart(), membershipDate->getPeriod(), lockerNum));
			memberList.erase(memberList.begin() + i);
			break;
		}
	}
}
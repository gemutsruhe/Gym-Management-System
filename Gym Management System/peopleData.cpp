#include "peopleData.h"
#include "ptRelation.h"
#include <fstream>
#include <string>
#include <vector>
#include "iostream"
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
		if(((member *)memberList[i])->getID() == id){
			ptMemberList.push_back(new ptMember(((member*)memberList[i]), trainerID, ptNum, healthData));
			memberList.erase(memberList.begin() + i);
			break;
		}
	}
}

void peopleData::addStaff(std::string name, std::string phone_num, int salary){
	staffList.push_back(new staff(name, phone_num, salary));
}

void peopleData::addTrainer(std::string name, std::string phone_num, int salary){
	trainer *newTrainer = new trainer(name, phone_num, salary, *(new std::vector<std::string>));
	trainerList.push_back(newTrainer);
}

void peopleData::addHealthData(std::string memberID, health *newHealthData){
	for(int i = 0; i < memberList.size(); i++){
		if(((member *)memberList[i])->getID() == "memberID"){
			
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

std::vector<people *> peopleData::getPTMemberList() {
	return ptMemberList;
}
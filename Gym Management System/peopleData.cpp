#include "peopleData.h"
#include "ptRelation.h"
#include <fstream>
#include <string>
#include <vector>

bool peopleData::loadData() {
	
	std::string fileName = "member.txt";
	std::ifstream file;

	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
			
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
		createFile.close();
	}
	file.close();

	fileName = "ptMember.txt";
	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
		createFile.close();
	}
	file.close();

	fileName = "staff.txt";
	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
		createFile.close();
	}
	file.close();

	fileName = "trainer.txt";
	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
		createFile.close();
	}
	file.close();

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
	memberList.push_back(*newMember);
}
void peopleData::memberToPT(std::string id, std::string trainerID, int ptNum, health *healthData){
	for(int i = 0; i < memberList.size(); i++){
		if(memberList[i].getID() == id){

			ptMember *newPTMember = new ptMember(&memberList[i], trainerID, ptNum, healthData);
			memberList.erase(memberList.begin() + i);
			break;
		}
	}
}
void peopleData::addStaff(){

}
void peopleData::addTrainer(std::string name, std::string phone_num, int salary){
	trainer *newTrainer = new trainer(name, phone_num, salary);
	trainerList.push_back(*newTrainer);
}

void peopleData::addHealthData(std::string memberID, health *newHealthData){
	for(int i = 0; i < memberList.size(); i++){
		if(memberList[i].getID() == "memberID"){
			
		}
	}
}

void peopleData::loadFile(std::string fileName, std::vector<people> peopleList){
	std::ifstream file;
	if(fileName == "member.txt") 
	file.open(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			std::string line;
			getline(file, line);
			
		}
	}
	else {
		std::ofstream createFile;
		createFile.open(fileName);
	}
}

void peopleData::exportFile(std::string fileName, std::vector<people> peopleList) {
	std::ofstream file;
	file.open(fileName, std::ios::out);
	if (file.is_open()) {
		for (int i = 0; i < memberList.size(); i++) file << memberList[i].toFile() << std::endl;
	}
}
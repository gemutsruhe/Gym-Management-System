#include "peopleData.h"
#include "ptRelation.h"
#include <fstream>
#include <string>
#include <vector>

bool peopleData::loadData() {
	
	loadFile("member.txt");
	loadFile("ptMember.txt");
	loadFile("staff.txt");
	loadFile("trainer.txt");

}

bool peopleData::exportData() {
	std::ofstream file;
	file.open("memberData.txt", std::ios::out);
	if (file.is_open()) {
		for (int i = 0; i < memberList.size(); i++) file << memberList[i].toFile() << std::endl;
	}
	file.open("staffData.txt");
	if(file.is_open()){
		for (int i = 0; i < staffList.size(); i++) file << staffList[i].toFile() << std::endl;
	}
	staff;
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

void peopleData::loadFile(std::string fileName){
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
	}
}
#include "peopleData.h"
#include <fstream>
#include <string>
#include <vector>

bool peopleData::loadData() {
	ifstream file;
	file.open("memberData.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string line;
			getline(file, line);
		}
	}
	else {
		ofstream createFile;
		createFile.open("memberData.txt");
	}
	file.open("staffData.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string line;
			getline(file, line);
		}
	}
	else {
		ofstream createFile;
		createFile.open("staffData.txt");
	}
}

void peopleData::exportData() {
	ofstream file;
	file.open("memberData.txt", ios::out);
	if (file.is_open()) {
		for (int i = 0; i < memberList.size(); i++) file << memberList[i].toFile() << endl;
	}
	file.open("staffData.txt");
	if(file.is_open()){
		for (int i = 0; i < staffList.size(); i++) file << staffList[i].toFile() << endl;
	}
	staff;
}
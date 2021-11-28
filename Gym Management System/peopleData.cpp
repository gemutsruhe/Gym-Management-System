#include "peopleData.h"
#include <fstream>
#include <string>
#include <vector>

void peopleData::loadData() {
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
		for (int i = 0; i < member.size(); i++) file << member.output();
	}
	for (int i = 0; i < staff.size(); i++) {

	}
	staff;
}
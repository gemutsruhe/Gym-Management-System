#include "peopleData.h"
#include <fstream>
#include <string>
#include <vector>

void PeopleData::loadData() {
	ifstream readFile;
	readFile.open("memberData.txt");
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string line;
			getline(readFile, line);

		}
	}
	readFile.open("staffData.txt");
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string line;
			getline(readFile, line);
		}
	}
}
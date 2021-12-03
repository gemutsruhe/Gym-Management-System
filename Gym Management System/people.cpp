#include "people.h"

std::string people::getID() {
	return id;
}

std::string people::getName(){
    return name;
}

std::string people::getPhone_num(){
    return phone_num;
}

std::string people::dataToString() {
    return "";
}

people* people::parseString(std::string data) {
    return new people();
}

std::vector<std::string> people::split(std::string data, char e) {
	std::vector<std::string> splitString;
	int i, j = 0, substrStart = 0;
	if (data.size() == 0) return splitString;
	for (i = 0; i < data.size(); i++) {
		if (data[i] == e) {
			splitString.push_back(data.substr(substrStart, i - substrStart));
			substrStart = i + 1;
			j++;
		}
	}
	splitString.push_back(data.substr(substrStart, i - substrStart));
	return splitString;
}
#include "health.h"
#include <sstream>

#define STRING(num) STR(num)
#define STR(num) #num

health::health(std::string data) {
	std::vector<std::string> splitString;
	int i, j = 0, substrStart = 0;
	for (i = 0; i < data.size(); i++) {
		if (data[i] == '-') {
			splitString.push_back(data.substr(substrStart, i - substrStart));
			substrStart = i + 1;
			j++;
		}
	}
	splitString.push_back(data.substr(substrStart, i - substrStart));
	this->height = std::stof(splitString[0]);
	this->weight = std::stof(splitString[1]);
	this->muscle = std::stof(splitString[2]);
	this->fat = std::stof(splitString[3]);
}

health::health(float height, float weight, float muscle, float fat){
	this->height = height;
	this->weight = weight;
	this->muscle = muscle;
	this->fat = fat;
}

float health::getBMI() {
	return weight / (height / 100 * height / 100);
}
float health::getFatPercent() {
	return fat / weight * 100;
}

std::string health::toString() {
	std::ostringstream buffer;
	buffer << height << "-" << weight << "-" << muscle << "-" << fat;
	return buffer.str();
}
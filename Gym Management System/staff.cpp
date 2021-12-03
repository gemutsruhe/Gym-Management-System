#include "staff.h"

staff::staff() {

}

staff::staff(std::string name, std::string phone_num, int salary) {
	this->name = name;
	this->phone_num = phone_num;
	this->salary = salary;
}

std::string staff::dataToString(){
    return name + " " + phone_num + " " + std::to_string(salary);
}

people *staff::parseString(std::string dataString){
    int substrStart = 0;
	std::string split[3];
	int j = 0;
	for(int i = 0; i < dataString.size(); i++){
		if(dataString[i] == ' ') {
			split[j] = dataString.substr(substrStart,i - substrStart);
			i = substrStart;
			j++;
		}
	}
	return new staff(split[0], split[1], stoi(split[2]));
}
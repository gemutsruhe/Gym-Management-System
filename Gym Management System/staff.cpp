#include "staff.h"

staff::staff() {

}

staff::staff(std::string id, std::string name, std::string phone_num, int salary) {
	this->id = id;
	this->name = name;
	this->phone_num = phone_num;
	this->salary = salary;
}

std::string staff::dataToString(){
    return id + " " + name + " " + phone_num + " " + std::to_string(salary);
}

people *staff::parseString(std::string dataString){
    int substrStart = 0;
	std::vector<std::string> split = (new people())->split(dataString, ' ');
	return new staff(split[0], split[1], split[2], stoi(split[3]));
}
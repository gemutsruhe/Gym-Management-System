#pragma once
#include <string>
#include <vector>
class people {
protected:
	std::string id;
	std::string name;
	std::string phone_num;
public:
	std::string getID();
	std::string getName();
	std::string getPhone_num();
	static std::string dataToString();
	virtual people *parseString(std::string);
	std::vector<std::string> split(std::string, char);
};
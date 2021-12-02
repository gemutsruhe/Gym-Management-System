#include "staff.h"

virtual std::string staff::dataToStinrg(){
    return this->name + " " + phone_num + " " + std::to_string(salary);
}

virtual people staff::*parseString(std::string dataString){
    int substrStart = 0;
	vector<std::string> split;
	for(int i = 0; i < dataString.size(); i++){
		if(dataString[i] == " "){
			split.push_back(dataString.substr(substrStart,i - substrStart));
			i = substrStart;
		}
	}
}
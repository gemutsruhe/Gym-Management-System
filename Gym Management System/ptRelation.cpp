#include "ptRelation.h"

void trainer::addPTMember(ptMember* newMember) {
	this->chargePTMember.push_back(newMember);
}

void trainer::deletePTMember(std::string id) {
	for (int i = 0; i < chargePTMember.size(); i++) {
		if (chargePTMember[i]->getID() == id) {
			chargePTMember.erase(chargePTMember.begin() + i);
			break;
		}
	}
}

ptMember::ptMember(member *newPTMember, int, std::vector<std::string>, trainer *chargeTrainer, health *measure) {

}


std::string ptMember::toFile() {
	std::string trainedDateStr = "";
	int i;
	for (i = 0; i < trainedDate.size() - 1; i++) trainedDateStr += trainedDate[i] + ",";
	trainedDateStr += trainedDate[i];
	std::string healthDataStr = "";
	for(i = 0; i < healthData.size() - 1; i++) healthDataStr += healthData[i].toString() + ",";
	healthDataStr += healthData[i].toString();
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + std::to_string(lockerNum) + " " + trainerID + " " + std::to_string(remainPT) + " " + trainedDateStr + " " + healthDataStr;
}

void ptMember::updateHealth(health recentData) {
	healthData.push_back(recentData);
}
void changeTrainer();
void addTrainedDate(std::string);
void extendPT(int);

std::string ptMember::getID() {
	return id;
}
#include "ptRelation.h"

void trainer::addPTMember(ptMember* newMember) {
	this->chargePTMember.push_back(newMember);
}

void trainer::deletePTMember(string id) {
	for (int i = 0; i < chargePTMember.size(); i++) {
		if (chargePTMember[i]->getID() == id) {
			chargePTMember.erase(chargePTMember.begin() + i);
			break;
		}
	}
}

ptMember::ptMember(member *newPTMember, int, vector<string>, trainer *chargeTrainer, health *measure) {

}


string ptMember::toFile() {
	string trainedDateStr;
	int i;
	for (i = 0; i < trainedDate.size() - 1; i++) trainedDateStr = trainedDate[i] + ",";
	trainedDateStr += trainedDate[i];
	for(i = 0; i < healthData.size() - 1; i++)
	return id + " " + name + " " + phone_num + " " + membership->getMembershipStart() + " " + to_string(lockerNum) + " " + trainerID + " " + to_string(remainPT) + " " + trainedDateStr + " " + ;
}

void ptMember::updateHealth(health recentData) {
	healthData.push_back(recentData);
}
void changeTrainer();
void addTrainedDate(string);
void extendPT(int);

string ptMember::getID() {
	return id;
}
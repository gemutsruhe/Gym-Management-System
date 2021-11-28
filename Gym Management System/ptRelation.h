#pragma once
#include "member.h"
#include "staff.h"
#include <vector>
#include "health.h"

class trainer;

class ptMember : member {
private:
	int remainPT;
	vector<string> trainedDate;
	string trainerID;
	vector<health> healthData;
public:
	ptMember(member *, int, vector<string>, trainer *, health *);
	void updateHealth(health);
	void changeTrainer();
	void addTrainedDate(string);
	void extendPT(int);
	string getID();
	string toFile();
};

class trainer : public staff {
private:
	vector<ptMember *> chargePTMember;
public:
	void showSchedule();
	void addPTMember(ptMember*);
	void deletePTMember(string);
};
#pragma once
#include "member.h"
#include "staff.h"
#include <vector>
#include "health.h"

class trainer;

class ptMember : member {
private:
	int remainPT;
	std::vector<std::string> trainedDate;
	std::string trainerID;
	std::vector<health> healthData;
public:
	ptMember(member *, int, std::vector<std::string>, trainer *, health *);
	void updateHealth(health);
	void changeTrainer();
	void addTrainedDate(std::string);
	void extendPT(int);
	std::string getID();
	virtual std::string toFile();
};

class trainer : public staff {
private:
	std::vector<ptMember *> chargePTMember;
public:
	void showSchedule();
	void addPTMember(ptMember*);
	void deletePTMember(std::string);
	virtual std::string toFile();
};
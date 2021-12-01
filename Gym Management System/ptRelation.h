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
	ptMember(member *, std::string, int, health *);
	void addNewHealth(health *);
	void changeTrainer(std::string);
	void addTrainedDate(std::string);
	void extendPT(int);
	std::string getID();
	virtual std::string toFile();
};

class trainer : public staff {
private:
	std::vector<ptMember *> chargePTMember;
public:
	trainer(std::string, std::string, int);
	void showSchedule();
	void addPTMember(ptMember*);
	void deletePTMember(std::string);
	virtual std::string toFile();
};
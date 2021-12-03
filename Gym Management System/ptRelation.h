#pragma once
#include "member.h"
#include "staff.h"
#include "health.h"

class trainer;

class ptMember : public member {
private:
	int remainPT;
	std::vector<std::string> trainedDate;
	std::string trainerID;
	std::vector<health *> healthData;
private:
	std::string trainedDateToString();
	std::string healthDataToString();

public:
	ptMember();
	ptMember(member *, std::string, int, health *);
	ptMember(std::string id, std::string name, std::string phone_num, std::string membership_start, int period, int lockerNum, int remainPT, std::vector<std::string> trainedDate, std::string trainerID, std::vector<health *> healthData);
	void addNewHealth(health *);
	void changeTrainer(std::string);
	void addTrainedDate(std::string);
	void extendPT(int);
	std::string getID();
	
	virtual std::string dataToString();
	virtual people* parseString(std::string);
};

class trainer : public staff {
private:
	std::vector<std::string> chargePTMember;
public:
	trainer();
	trainer(std::string id, std::string, std::string, int, std::vector<std::string>);
	void addPTMember(std::string);
	void deletePTMember(std::string);

	virtual std::string dataToString();
	virtual people* parseString(std::string);
};


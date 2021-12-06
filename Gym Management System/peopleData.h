#include "ptRelation.h"

class peopleData {
private:
	std::vector<people *> memberList;
	std::vector<people *> ptMemberList;
	std::vector<people *> staffList;
	std::vector<people *> trainerList;
private:
	void loadFile(std::string, std::vector<people *> *, people*);
	void exportFile(std::string, std::vector<people *>);
public:
	peopleData();
	bool loadData();
	bool exportData();
	void addMember(std::string, std::string, std::string, std::string, int, int);
	bool memberToPT(std::string, std::string, int, health *);
	bool chargeMember(std::string, std::string);
	void addStaff(std::string, std::string, std::string, int);
	void addTrainer(std::string, std::string, std::string, int);
	void addHealthData(std::string, health *);
	void addTrainedDate(std::string, std::string);
	std::vector<std::string> getTrainerData();
	std::string getMembershipEnd(std::string);
	std::vector<std::string> getPTMemberData();
	void transferMembership(std::string, std::string, std::string, std::string, int);
	void extendMembership(std::string, int);
	void extendPTNumber(std::string, int);
};
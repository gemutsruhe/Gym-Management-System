#include "ptRelation.h"

class peopleData {
private:
	std::vector<member> memberList;
	std::vector<ptMember> ptMemberList;
	std::vector<staff> staffList;
	std::vector<trainer> trainerList;
private:
	void loadFile(std::string);
	void exportFile(std::string);
public:
	bool loadData();
	bool exportData();
	void addMember(std::string, std::string, std::string, std::string, int, int);
	void memberToPT(std::string, std::string, int, health *);
	void addStaff();
	void addTrainer(std::string, std::string, int);
	void addHealthData(std::string, health *);
};
#include "ptRelation.h"

class peopleData {
private:
	std::vector<people *> memberList;
	std::vector<people *> ptMemberList;
	std::vector<people *> staffList;
	std::vector<people *> trainerList;
private:
	void loadFile(std::string);
	void exportFile(std::string, std::vector<people *>);
public:
	peopleData();
	bool loadData();
	bool exportData();
	void addMember(std::string, std::string, std::string, std::string, int, int);
	void memberToPT(std::string, std::string, int, health *);
	void addStaff(std::string,std::string,int);
	void addTrainer(std::string, std::string, int);
	void addHealthData(std::string, health *);
	std::vector<people *> getPTMemberList();
};
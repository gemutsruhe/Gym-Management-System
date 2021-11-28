#include <string>
#include <time.h>
#include <vector>
#include "health.h"
#include "date.h"

using namespace std;

class people {
protected:
	string name;
	string phone_num;
};

class member : People {
protected:
	string id;
	date membership;
	int lockerNum;
public:
	member(string, string, string, string, string, int);
	void extendMembership(int);
	void changeLocker();
};

class staff : People {
protected:
	int salary;
};

class ptMember : Member {
private:
	int remainPT;
	vector<string> trainedDate;
	Trainer personalTrainer;
	health myData;
public:
	ptMember(int, vector<string>, Trainer, health);
	void updateHealth(health);
	void changeTrainer();
	void addTrainedDate(string);
	void extendPT(int);
};

class trainer : public Staff {
private:
	vector<PTMember> chargePTMember;
public:
	void showSchedule();
	void addPTMember(PTMember);
	void deletePTMember(PTMember);
};
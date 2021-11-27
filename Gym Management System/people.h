#include <string>
#include <time.h>
#include <vector>
#include "health.h"
using namespace std;

class People {
protected:
	string name;
	string phone_num;
public:
	People(string, string);
};

class Member : People {
protected:
	string id;
	string membership_start;
	string membership_end;
	int lockerNum;
public:
	Member(string, string, string, string, int);
	void extendMembership(int);
};

class Staff : People {
protected:
	int salary;
};

class PTMember : Member {
private:
	int remainPT;
	vector<string> trainDate;
	Trainer personalTrainer;
	health myData;
public:
	PTMember(int, vector<string>, Trainer, health);
	void updateHealth(health);
};

class Trainer : Staff {
private:
	vector<PTMember> chargePTMember;
public:
	void addPTMember(PTMember *);
	void showSchedule();
	void addPT(PTMember);
	void deletePT(PTMember);
};
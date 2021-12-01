#include "ptRelation.h"

using namespace std;

class peopleData {
private:
	vector<member> memberList;
	vector<staff> staffList;
public:
	bool loadData();
	void exportData();
};
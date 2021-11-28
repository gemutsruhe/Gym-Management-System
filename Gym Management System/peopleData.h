#include "ptRelation.h"

using namespace std;

class peopleData {
private:
	vector<member> member;
	vector<staff> staff;
public:
	void loadData();
	void exportData();
};
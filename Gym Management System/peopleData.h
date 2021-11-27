
#include "people.h"

using namespace std;

class PeopleData {
private:
	vector<Member> member;
	vector<Staff> staff;
public:
	void loadData();
};
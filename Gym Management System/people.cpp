#include "People.h"

People::People(string name, string phone_num) {
	this->name = name;
	this->phone_num = phone_num;
}


Member::Member(string, string, string, string, int) {

}
	void extendMembership(int);

void Trainer::addPTMember(PTMember *newMember){
	this->chargePTMember.push_back(*newMember);
}
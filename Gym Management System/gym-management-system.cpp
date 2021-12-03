#include <iostream>
#include "peopleData.h"

using namespace std;

int main() {
	peopleData *data = new peopleData();
	data->loadData();
	int input;
	while(true){
		cout << "1. regist new member" << endl;
		cout << "2. convert member to ptMember" << endl;
		cout << "3. regist new staff" << endl;
		cout << "4. regist new trainer" << endl;
		cout << "5. insert new healthData" << endl;
		cout << "6. insert trained Date" << endl;
		cout << "if input 0, save, exit" << endl;
		
		cin >> input;
		switch(input){
		case 0:
		{
			data->exportData();
			return 0;
		}	
		case 1:
		{
			string id = "", name = "", phone_num(""), membership_start("");
			int period = 0, lockerNum = 0;
			cout << "enter id : ";
			cin >> id;
			cout << "enter name : ";
			cin >> name;
			cout << "enter phone number : ";
			cin >> phone_num;
			cout << "enter membership start date : ";
			cin >> membership_start;
			cout << "enter gym regist period : ";
			cin >> period;
			cout << "enter locker number : ";
			cin >> lockerNum; 
			data->addMember(id, name, phone_num, membership_start, period, lockerNum);
			break;
		}
		case 2:
		{
			int ptNum = 0;
			float height = 0, weight = 0, muscle = 0, fat = 0;
			string memberID = "", trainerID = "";
			cout << "enter memberID : ";
			cin >> memberID;
			cout << "enter trainerID : ";
			cin >> trainerID;
			cout << "enter training num : ";
			cin >> ptNum;
			cout << "enter height weight muscle fat : ";
			cin >> height >> weight >> muscle >> fat;
			data->memberToPT(memberID, trainerID, ptNum, new health(height, weight, muscle, fat));
			data->chargeMember(trainerID, memberID);
			break;
		}
		case 3:
		{
			string id, name, phone_num;
			int salary = 0;
			cout << "enter id : ";
			cin >> id;
			cout << "enter name : ";
			cin >> name;
			cout << "enter phone number : ";
			cin >> phone_num;
			cout << "enter salary : ";
			cin >> salary;
			data->addStaff(id, name,phone_num,salary);
			break;
		}
		case 4:
		{
			string id, name, phone_num;
			int salary = 0;
			cout << "enter id : ";
			cin >> id;
			cout << "enter trainer name : ";
			cin >> name;
			cout << "enter trainer phone number : ";
			cin >> phone_num;
			cout << "enter salary : ";
			cin >> salary;
			data->addTrainer(id, name, phone_num, salary);
			break;
		}
		case 5:
		{
			string memberID = "";
			float height = 0, weight = 0, muscle = 0, fat = 0;
			cout << "enter ptMemberID : ";
			cin >> memberID;
			cout << "enter height weight muscle fat : ";
			cin >> height >> weight >> muscle >> fat;
			data->addHealthData(memberID, new health(height, weight, muscle, fat));
			break;
		}
		case 6:
		{
			string id, trainedDate;
			cout << "enter member id : ";
			cin >> id;
			cout << "enter date : ";
			cin >> trainedDate;
			data->addTrainedDate(id, trainedDate);
		}
		case 10:
		{
			vector<people*> ptMemberList = data->getPTMemberList();
			for (int i = 0; i < ptMemberList.size(); i++) {
				cout << ((ptMember*)ptMemberList[i])->dataToString() << endl;
			}
			break;
		}
		}
	}

	data->exportData();
	return 0;
}
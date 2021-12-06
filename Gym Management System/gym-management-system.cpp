#include <iostream>
#include "peopleData.h"

using namespace std;

int main() {
	peopleData *data = new peopleData();
	data->loadData(); // 저장된 데이터 가져오기 // 보기전에 exportData먼저 보시면 이해가 빠를거에요
	int input;
	while(true){
		cout << "1. regist new member" << endl;
		cout << "2. convert member to ptMember" << endl;
		cout << "3. regist new staff" << endl;
		cout << "4. regist new trainer" << endl;
		cout << "5. insert new healthData" << endl;
		cout << "6. insert trained date" << endl;
		cout << "7. show membership end date" << endl;
		cout << "8. show trainer list" << endl;
		cout << "9. show ptMember List" << endl;
		cout << "10. transfer membership" << endl;
		cout << "11. extend membership" << endl;
		cout << "12. extend pt times" << endl;
		cout << "if input 0, save and exit" << endl;
		
		cin >> input;
		switch(input){
		case 0:
		{
			data->exportData(); // 데이터 내보내기(저장)
			return 0;
		}	
		case 1:
		{
			string id, name, phone_num, membership_start;
			int period, lockerNum;
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
			data->addMember(id, name, phone_num, membership_start, period, lockerNum); // member 신규 등록
			break;
		}
		case 2:
		{
			int ptNum;
			float height, weight, muscle, fat;
			string memberID, trainerID;
			cout << "enter memberID : ";
			cin >> memberID;
			cout << "enter trainerID : ";
			cin >> trainerID;
			cout << "enter training num : ";
			cin >> ptNum;
			cout << "enter height weight muscle fat : ";
			cin >> height >> weight >> muscle >> fat;
			data->memberToPT(memberID, trainerID, ptNum, new health(height, weight, muscle, fat)) && data->chargeMember(trainerID, memberID);
			//member를 ptMember로 전환 // 전환 성공 시 trainer에게 ptMember 할당
			break;
		}
		case 3:
		{
			string id, name, phone_num;
			int salary;
			cout << "enter id : ";
			cin >> id;
			cout << "enter name : ";
			cin >> name;
			cout << "enter phone number : ";
			cin >> phone_num;
			cout << "enter salary : ";
			cin >> salary;
			data->addStaff(id, name,phone_num,salary); // 새로운 staff 등록
			break;
		}
		case 4:
		{
			string id, name, phone_num;
			int salary;
			cout << "enter id : ";
			cin >> id;
			cout << "enter trainer name : ";
			cin >> name;
			cout << "enter trainer phone number : ";
			cin >> phone_num;
			cout << "enter salary : ";
			cin >> salary;
			data->addTrainer(id, name, phone_num, salary); // 새로운 trainer 등록 // staff와 모두 같아 loadData와 같이 사용할 수 있으나 그냥 이렇게 놔두었음
			break;
		}
		case 5:
		{
			string memberID;
			float height, weight, muscle, fat;
			cout << "enter ptMemberID : ";
			cin >> memberID;
			cout << "enter height weight muscle fat : ";
			cin >> height >> weight >> muscle >> fat;
			data->addHealthData(memberID, new health(height, weight, muscle, fat)); // health data 추가
			break;
		}
		case 6:
		{
			string id, trainedDate;
			cout << "enter member id : ";
			cin >> id;
			cout << "enter date : ";
			cin >> trainedDate;
			data->addTrainedDate(id, trainedDate); // case 5와 마찬가지로 동작
			break;
		}
		case 7:
		{
			string id;
			cout << "enter member id : ";
			cin >> id;
			cout << data->getMembershipEnd(id) << endl; // member id를 받아 멤버십이 끝나는 날을 출력
			break;
		}
		case 8:
		{
			vector<string> trainerList = data->getTrainerData(); // trainer 목록 출력
			for (int i = 0; i < trainerList.size(); i++)
				cout << trainerList[i] << endl;
			break;
		}
		case 9:
		{
			vector<string> ptMemberList = data->getPTMemberData(); // ptMember list 출력 (member list와 staff list 동일해서 생략)
			for (int i = 0; i < ptMemberList.size(); i++)
				cout << ptMemberList[i] << endl;
			break;
		}
		case 10:
			{
			string prevID, id, name, phoneNum;
			int lockerNum;
			cout << "enter member id : ";
			cin >> prevID;
			cout << "enter new member id : ";
			cin >> id;
			cout << "enter new member name : ";
			cin >> name;
			cout << "enter new member phone number : ";
			cin >> phoneNum;
			cout << "enter locker num : ";
			cin >> lockerNum;
			data->transferMembership(prevID, id, name, phoneNum, lockerNum); // membership 양도 id, name, phoneNum, lockerNum 변환
			break;
		}
		case 11:
		{
			string id;
			int extendPeriod;
			cout << "enter member id : ";
			cin >> id;
			cout << "enter extend period : ";
			cin >> extendPeriod;
			data->extendMembership(id, extendPeriod); // membership 연장
			break;
		}
		case 12:
		{
			string id;
			int ptNum;
			cout << "enter id : ";
			cin >> id;
			cout << "enter extend pt times : ";
			cin >> ptNum;
			data->extendPTNumber(id, ptNum); // extend training number
			break;
		}
		}
	}
	return 0;
}
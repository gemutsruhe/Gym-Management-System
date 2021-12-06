#include "date.h"

date::date(std::string membership_start, int period) {
    this->year = membership_start.substr(0, 4);
    this->month = membership_start.substr(5, 2);
    this->day = membership_start.substr(8, 2);
    this->period = period;
}
std::string date::getMembershipStart(){
    std::string date(year + "-" + month + "-" + day);
    return date;
}

int date::getPeriod() {
    return this->period;
}

std::string date::getMembershipEnd(){ // duration�� �Ѵ��� 30�Ϸ� ��� return �� ���´� 1900-01-01
    int duration = 30 * this->period - 1; // ������ �����̹Ƿ� -1
    int endYear = stoi(this->year);
    int endMonth = stoi(this->month);
    int endDay = stoi(this->day);
    int dayOfMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(duration >= 1){
        if(endYear % 4 == 0 && endYear % 100 != 0) dayOfMonth[2] = 29;
        endDay += duration;
        
        if (endDay > dayOfMonth[endMonth]) {
            duration = endDay - dayOfMonth[endMonth];
            endMonth++;
            if (endMonth == 13) {
                endMonth = 1;
                endYear++;
            }
            endDay = 0;
        }
        else break;
    }
    std::string month = (endMonth / 10) == 0 ? "0" + std::to_string(endMonth) : std::to_string(endMonth);
    std::string day = (endDay / 10) == 0 ? "0" + std::to_string(endDay) : std::to_string(endDay);
    std::string date = std::to_string(endYear) + "-" + month + "-" + day;
    return date;
}

void date::extendPeriod(int month){
    this->period += month;
}
int date::getRemainDay(){
    int duration = 3 * this->period;
    return duration;
}

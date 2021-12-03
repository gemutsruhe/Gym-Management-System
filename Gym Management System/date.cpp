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

std::string date::getMembershipEnd(){
    int duration = 30 * this->period;
    int endYear = stoi(this->year);
    int endMonth = stoi(this->month);
    int endDay = stoi(this->day);
    int dayOfMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(duration >= 1){
        if(endYear % 4 == 0 && endYear % 100 != 0) dayOfMonth[2] = 29;
        else dayOfMonth[2] = 28;
        endDay += duration;
        if(endDay > dayOfMonth[endMonth]){
            duration = endDay - dayOfMonth[endMonth];
            endMonth++;
            if(endMonth == 13) {
                endMonth = 1;
                endYear++;
            }
            endDay = 0;
        }
    }
    std::string date(std::to_string(endYear) + "-" + std::to_string(endMonth) + "-" + std::to_string(endDay));
    return date;
}

void date::extendPeriod(int month){
    this->period += month;
}
int date::getRemainDay(){
    int duration = 3 * this->period;
    return duration;
}

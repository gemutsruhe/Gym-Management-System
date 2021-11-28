date::date(int year, int month, int day, int period){
    this->year = year;
    this->month = month;
    this->day = day;
    this->period = period;
}

string date::getMembershipStart(){
    string date(year + "-" + month + "-" + day);
    return date;
}

string date::getMembershipEnd(){
    int duration = 30 * this->period;
    int endYear = this->year;
    int endMonth = this->month;
    int endDay = this->day;
    int []dayOfMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(duration >= 1){
        if(endYear % 4 == 0 && endYear % 100 != 0) dayOfMonth = 29;
        else dayOfMonth = 28;
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
    string date(endYear + "-" + endMonth + "-" + day);
    return date;
}

void date::extendPeriod(int month){
    this->period += month;
}
int date::getRemainDay(){
    int duration = 3 * this->period;
}
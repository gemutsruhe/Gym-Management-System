#include <string>
#include <time.h>
#include <vector>
#include <ctime>
using namespace std;

class date {
private:
	int year;
	int month;
	int day;
	int period;
public:
	Date(int, int, int, int);
	string getMembershipStart();
	string getMembershipEnd();
	int getRemainDay();
	void extendPeriod(int);
};

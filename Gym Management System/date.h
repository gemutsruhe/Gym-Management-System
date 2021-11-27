#include <string>
#include <time.h>
#include <vector>
#include <ctime>
using namespace std;

class Date {
protected:
	CTime t1 = CTime::GetCurrentTime();
	time_t start;
	time_t end;
public:
	Date(string);
};

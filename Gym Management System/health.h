#pragma once
#include <vector>
#include <string>
using namespace std;
class health {
private:
	float height;
	float weight;
	float muscle;
	float fat;
public:
	float getBMI();
	float getFatPercent();
	string toString();
};
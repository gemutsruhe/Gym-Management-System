#pragma once
#include <vector>
using namespace std;
class health {
private:
	float height;
	vector<float> weight;
	vector<float> muscle;
	vector<float> fat;
public:
	float getBMI();
	float getFatPercent();
};
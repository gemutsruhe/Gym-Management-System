#pragma once
#include <vector>
#include <string>

class health {
private:
	float height;
	float weight;
	float muscle;
	float fat;
public:
	float getBMI();
	float getFatPercent();
	std::string toString();
};
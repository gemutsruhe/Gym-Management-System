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
	health(float, float, float, float);
	health(std::string);
	float getBMI();
	float getFatPercent();
	std::string toString();
};
#include "health.h"

health::health(float height, float weight, float muscle, float fat){
	this->height = height;
	this->weight = weight;
	this->muscle = muscle;
	this->fat = fat;
}

float health::getBMI() {
	return weight / (height / 100 * height / 100);
}
float health::getFatPercent() {
	return fat / weight * 100;
}

std::string health::toString() {
	return std::to_string(height) + "/" + std::to_string(weight) + "/" + std::to_string(muscle) + "/" + std::to_string(fat);
}
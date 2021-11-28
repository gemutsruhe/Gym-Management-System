#include "health.h"

float health::getBMI() {
	return weight / (height / 100 * height / 100);
}
float health::getFatPercent() {
	return fat / weight * 100;
}

string health::toString() {
	return to_string(height) + "/" + to_string(weight) + "/" + to_string(muscle) + "/" + to_string(fat);
}
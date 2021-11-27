#include "health.h"

float health::getBMI() {
	return weight[weight.size() - 1] / (height / 100 * height / 100);
}
float health::getFatPercent() {
	return fat[fat.size() - 1] / weight[weight.size() - 1] * 100;
}
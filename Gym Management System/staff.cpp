#include "staff.h"

std::string staff::toFile(){
    return name + " " + phone_num + " " + std::to_string(salary);
}
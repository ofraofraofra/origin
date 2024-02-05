#include "Vehicle.h"


Vehicle::Vehicle(const std::string& n, const int& s) : name(n), speed(s) {}
std::string Vehicle::getName() const { return name; }
double Vehicle::calculateTime(double distance) const { //итоговое время
    return 0;
}
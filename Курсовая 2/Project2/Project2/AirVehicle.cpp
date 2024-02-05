#include "AirVehicle.h"


AirVehicle::AirVehicle(const std::string& n, const int& s) : Vehicle(n, s) {}
double AirVehicle::calculateTime(double distance) const { //итоговое время
    return getDistanceReduced(distance) / speed;
}
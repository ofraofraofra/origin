#include "AirVehicle.h"


AirVehicle::AirVehicle(const std::string& n, const int& s) : Vehicle(n, s) {}
double AirVehicle::calculateTime(double distance) const { //�������� �����
    return getDistanceReduced(distance) / speed;
}
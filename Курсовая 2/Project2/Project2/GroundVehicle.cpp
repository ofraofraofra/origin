#include "GroundVehicle.h"


GroundVehicle::GroundVehicle(const std::string& n, const int& s) : Vehicle(n, s) {}
double GroundVehicle::calculateTime(double distance) const { //�������� �����        
    return (distance / speed + getTotalRestDuration(calculateRestCount(getRestDuration(), distance)));
}

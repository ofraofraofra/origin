#include "Eagle.h"


    Eagle::Eagle() : AirVehicle("Орёл", 8) {}
    double Eagle::getDistanceReduced(double distance) const { return distance * 0.94; }  // уменьшенное расстояние




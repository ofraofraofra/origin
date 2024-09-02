#include "Broomstick.h"

    Broomstick::Broomstick() : AirVehicle("Метла", 20) {}
    double Broomstick::getDistanceReduced(double distance) const {  // уменьшенное расстояние
        // Вычисляем, сколько раз нужно увеличить коэффициент на 1%
        int increaseCount = distance / 1000;
        // Возвращаем уменьшенное расстояние
        return distance * (1.0 - increaseCount / 100.0);
    }

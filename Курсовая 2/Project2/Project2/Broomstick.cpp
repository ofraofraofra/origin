#include "Broomstick.h"


    Broomstick::Broomstick() : AirVehicle("�����", 20) {}
    double Broomstick::getDistanceReduced(double distance) const {  // ����������� ����������
        return distance * (1.0 - std::min(1.0, distance / 1000) * 0.01);
    }


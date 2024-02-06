#include "Broomstick.h"

    Broomstick::Broomstick() : AirVehicle("�����", 20) {}
    double Broomstick::getDistanceReduced(double distance) const {  // ����������� ����������
        // ���������, ������� ��� ����� ��������� ����������� �� 1%
        int increaseCount = distance / 1000;
        // ���������� ����������� ����������
        return distance * (1.0 - increaseCount / 100.0);
    }

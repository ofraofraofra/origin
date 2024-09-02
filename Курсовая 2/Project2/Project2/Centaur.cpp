#include "Centaur.h"


Centaur::Centaur() : GroundVehicle("�������", 15) {}
    double Centaur::getRestDuration() const { return 8; } // ����� ������
    int Centaur::calculateRestCount(double timeToRest, double distance) const { // ���������� �������
        return int((
            ((distance / speed) - 0.01) / getRestDuration())
            );
    }
    double Centaur::getTotalRestDuration(int restCount) const { // ����� ����� ������
        if (restCount == 0) {
            return 0;
        }
        return double(restCount) * 2;
    }
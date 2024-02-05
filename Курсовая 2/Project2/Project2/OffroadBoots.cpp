#include "OffroadBoots.h"


    OffroadBoots::OffroadBoots() : GroundVehicle("�������-���������", 6) {}
    double OffroadBoots::getRestDuration() const { return 60; } // ����� ������
    int OffroadBoots::calculateRestCount(double timeToRest, double distance) const { // ���������� �������
        return int((
            (distance / speed) / getRestDuration())
            );
    }
    double OffroadBoots::getTotalRestDuration(int restCount) const { // ����� ����� ������
        if (restCount == 0) {
            return 0;
        }
        double firstRestDuration = 10.0; // ����������������� ������� ������
        double subsequentRestDuration = 5.0; // ����������������� ����������� �������
        // ����� ����� ������ = ����������������� ������� ������ + (���������� ������� - 1) * ����������������� ����������� �������
        return firstRestDuration + (double(restCount) - 1) * subsequentRestDuration;
    }
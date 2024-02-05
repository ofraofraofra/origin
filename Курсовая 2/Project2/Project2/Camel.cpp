#include "Camel.h"

Camel::Camel() : GroundVehicle("�������", 10) {}
double Camel::getRestDuration() const { return 30; } // ����� ������
int  Camel::calculateRestCount(double timeToRest, double distance) const { // ���������� �������
    return int((
        (distance / speed) / getRestDuration())
        );
}
double  Camel::getTotalRestDuration(int restCount) const { // ����� ����� ������
    if (restCount == 0) {
        return 0;
    }
    double firstRestDuration = 5.0; // ����������������� ������� ������
    double subsequentRestDuration = 8.0; // ����������������� ����������� �������
    // ����� ����� ������ = ����������������� ������� ������ + (���������� ������� - 1) * ����������������� ����������� �������
    return firstRestDuration + (double(restCount) - 1) * subsequentRestDuration;
}
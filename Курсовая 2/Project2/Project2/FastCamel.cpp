#include "FastCamel.h"


FastCamel::FastCamel() : GroundVehicle("�������-���������", 40) {}
double FastCamel::getRestDuration() const { return 10; } // ����� ������
int FastCamel::calculateRestCount(double timeToRest, double distance) const { // ���������� �������
    return int((
        (distance / speed) / getRestDuration())
        );
}
double FastCamel::getTotalRestDuration(int restCount) const { // ����� ����� ������
    if (restCount == 0) {
        return 0;
    }
    double firstRestDuration = 5.0; // ����������������� ������� ������
    double secondRestDuration = 6.5; // ����������������� ������� ������
    double subsequentRestDuration = 8.0; // ����������������� ����������� �������
    // ����� ����� ������ = ����������������� ������� ������ + ����������������� ������� ������ +
    //                          (���������� ������� - 2) * ����������������� ����������� �������
    return firstRestDuration + secondRestDuration + (double(restCount) - 2) * subsequentRestDuration;
}

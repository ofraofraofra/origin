#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "Vehicle.h"

class LIBRARY_API GroundVehicle : public Vehicle {
public:
    GroundVehicle(const std::string& n, const int& s);
    virtual double getRestDuration() const = 0; // ����� ������
    virtual int calculateRestCount(double timeToRest, double distance) const = 0; // ���������� �������
    virtual double getTotalRestDuration(int restCount) const = 0; // ����� ����� ������
    double calculateTime(double distance) const override;
};

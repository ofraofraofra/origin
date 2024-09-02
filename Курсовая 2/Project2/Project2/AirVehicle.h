#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "Vehicle.h"

class LIBRARY_API AirVehicle : public Vehicle {
public:
    AirVehicle(const std::string& n, const int& s);
    virtual double getDistanceReduced(double distance) const = 0; // уменьшенное расстояние
    double calculateTime(double distance) const override;
};
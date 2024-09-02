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
    virtual double getRestDuration() const = 0; // время отдыха
    virtual int calculateRestCount(double timeToRest, double distance) const = 0; // количество отдыхов
    virtual double getTotalRestDuration(int restCount) const = 0; // общее время отдыха
    double calculateTime(double distance) const override;
};

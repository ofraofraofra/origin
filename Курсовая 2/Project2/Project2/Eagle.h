#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "AirVehicle.h"

class LIBRARY_API Eagle : public AirVehicle {
public:
    Eagle();
    double getDistanceReduced(double distance) const override;

};



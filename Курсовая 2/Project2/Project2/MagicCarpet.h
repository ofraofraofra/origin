#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "AirVehicle.h"

class LIBRARY_API MagicCarpet : public AirVehicle {
public:
    MagicCarpet();
    double getDistanceReduced(double distance) const override;
};
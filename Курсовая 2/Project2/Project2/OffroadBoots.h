#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "GroundVehicle.h"

class LIBRARY_API OffroadBoots : public GroundVehicle {
public:
     OffroadBoots();
     double getRestDuration() const override;
     int calculateRestCount(double timeToRest, double distance) const;
     double getTotalRestDuration(int restCount) const;
};

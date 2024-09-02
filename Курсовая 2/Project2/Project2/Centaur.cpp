#include "Centaur.h"


Centaur::Centaur() : GroundVehicle("Кентавр", 15) {}
    double Centaur::getRestDuration() const { return 8; } // время отдыха
    int Centaur::calculateRestCount(double timeToRest, double distance) const { // количество отдыхов
        return int((
            ((distance / speed) - 0.01) / getRestDuration())
            );
    }
    double Centaur::getTotalRestDuration(int restCount) const { // общее время отдыха
        if (restCount == 0) {
            return 0;
        }
        return double(restCount) * 2;
    }
#include "OffroadBoots.h"


    OffroadBoots::OffroadBoots() : GroundVehicle("Ботинки-вездеходы", 6) {}
    double OffroadBoots::getRestDuration() const { return 60; } // время отдыха
    int OffroadBoots::calculateRestCount(double timeToRest, double distance) const { // количество отдыхов
        return int((
            (distance / speed) / getRestDuration())
            );
    }
    double OffroadBoots::getTotalRestDuration(int restCount) const { // общее время отдыха
        if (restCount == 0) {
            return 0;
        }
        double firstRestDuration = 10.0; // Продолжительность первого отдыха
        double subsequentRestDuration = 5.0; // Продолжительность последующих отдыхов
        // Общее время отдыха = продолжительность первого отдыха + (количество отдыхов - 1) * продолжительность последующих отдыхов
        return firstRestDuration + (double(restCount) - 1) * subsequentRestDuration;
    }
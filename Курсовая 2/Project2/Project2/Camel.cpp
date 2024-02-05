#include "Camel.h"

Camel::Camel() : GroundVehicle("Верблюд", 10) {}
double Camel::getRestDuration() const { return 30; } // время отдыха
int  Camel::calculateRestCount(double timeToRest, double distance) const { // количество отдыхов
    return int((
        (distance / speed) / getRestDuration())
        );
}
double  Camel::getTotalRestDuration(int restCount) const { // общее время отдыха
    if (restCount == 0) {
        return 0;
    }
    double firstRestDuration = 5.0; // Продолжительность первого отдыха
    double subsequentRestDuration = 8.0; // Продолжительность последующих отдыхов
    // Общее время отдыха = продолжительность первого отдыха + (количество отдыхов - 1) * продолжительность последующих отдыхов
    return firstRestDuration + (double(restCount) - 1) * subsequentRestDuration;
}
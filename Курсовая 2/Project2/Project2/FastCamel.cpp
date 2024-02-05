#include "FastCamel.h"


FastCamel::FastCamel() : GroundVehicle("Верблюд-быстроход", 40) {}
double FastCamel::getRestDuration() const { return 10; } // время отдыха
int FastCamel::calculateRestCount(double timeToRest, double distance) const { // количество отдыхов
    return int((
        (distance / speed) / getRestDuration())
        );
}
double FastCamel::getTotalRestDuration(int restCount) const { // общее время отдыха
    if (restCount == 0) {
        return 0;
    }
    double firstRestDuration = 5.0; // Продолжительность первого отдыха
    double secondRestDuration = 6.5; // Продолжительность второго отдыха
    double subsequentRestDuration = 8.0; // Продолжительность последующих отдыхов
    // Общее время отдыха = продолжительность первого отдыха + продолжительность второго отдыха +
    //                          (количество отдыхов - 2) * продолжительность последующих отдыхов
    return firstRestDuration + secondRestDuration + (double(restCount) - 2) * subsequentRestDuration;
}

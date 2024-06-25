#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Circle.h"

Circle::Circle(int _x1, int _y1, double _radius) : x1(_x1), y1(_y1), radius(_radius) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getVolume() const {
    return 0;
}

void Circle::shift(int m, int n, int k) {
    x1 += m; 
    y1 += n;
}

void Circle::scaleX(int factor) {
    x1 *= factor;
}

void Circle::scaleY(int factor) {
    y1 *= factor;
}

void Circle::scaleZ(int factor) {
}

void Circle::scale(int factor) {
    x1 /= factor; 
    y1 /= factor;
    radius /= factor;
}

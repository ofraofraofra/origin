#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Cylinder.h"

Cylinder::Cylinder(int _x1, int _y1, double _radius, double _height) : x1(_x1), y1(_y1), radius(_radius), height(_height) {}

double Cylinder::getArea() const {
    return 2 * M_PI * radius * (radius + height);
}

double Cylinder::getVolume() const {
    return M_PI * radius * radius * height;
}

void Cylinder::shift(int m, int n, int k) {
    x1 += m; 
    y1 += n;
}

void Cylinder::scaleX(int factor) {
    x1 *= factor;
}

void Cylinder::scaleY(int factor) {
    y1 *= factor;
}

void Cylinder::scaleZ(int factor) {}

void Cylinder::scale(int factor) {
    x1 /= factor;
    y1 /= factor;
    radius /= factor;
    height /= factor;
}

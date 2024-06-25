#include "Line.h"

Line::Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

double Line::getArea() const {
    return 0;
}

double Line::getVolume() const {
    return 0;
}

void Line::shift(int m, int n, int k) {
    x1 += m; 
    y1 += n;
    x2 += m;
    y2 += n;
}

void Line::scaleX(int factor) {
    x1 *= factor;
    x2 *= factor;
}

void Line::scaleY(int factor) {
    y1 *= factor;
    y2 *= factor;
}

void Line::scaleZ(int factor) {}

void Line::scale(int factor) {
    x1 /= factor;
    y1 /= factor;
    x2 /= factor;
    y2 /= factor;
}
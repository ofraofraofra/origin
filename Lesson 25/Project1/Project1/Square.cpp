#include "Square.h"

Square::Square(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4) {}

double Square::getArea() const {
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    return a * b;
}

double Square::getVolume() const {
    return 0;
}

void Square::shift(int m, int n, int k) {
    x1 += m; y1 += n;
    x2 += m; y2 += n;
    x3 += m; y3 += n;
    x4 += m; y4 += n;
}

void Square::scaleX(int factor) {
    x1 *= factor;
    x2 *= factor;
    x3 *= factor;
    x4 *= factor;
}

void Square::scaleY(int factor) {
    y1 *= factor;
    y2 *= factor;
    y3 *= factor;
    y4 *= factor;
}

void Square::scaleZ(int factor) {}

void Square::scale(int factor) {
    x1 /= factor; y1 /= factor;
    x2 /= factor; y2 /= factor;
    x3 /= factor; y3 /= factor;
    x4 /= factor; y4 /= factor;
}
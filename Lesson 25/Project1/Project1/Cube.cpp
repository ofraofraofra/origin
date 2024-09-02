#include "Cube.h"

Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
    : x1(_x1), y1(_y1), z1(_z1), x2(_x2), y2(_y2), z2(_z2), x3(_x3), y3(_y3), z3(_z3), x4(_x4), y4(_y4), z4(_z4), x5(_x5), y5(_y5), z5(_z5), x6(_x6), y6(_y6), z6(_z6), x7(_x7), y7(_y7), z7(_z7), x8(_x8), y8(_y8), z8(_z8) {}

double Cube::getArea() const {
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    int c = abs(z1 - z2);
    return 2 * a * b + 2 * a * c + 2 * b * c;
}

double Cube::getVolume() const {
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    int c = abs(z1 - z2);
    return a * b * c;
}

void Cube::shift(int m, int n, int k) {
    x1 += m; y1 += n; z1 += k;
    x2 += m; y2 += n; z2 += k;
    x3 += m; y3 += n; z3 += k;
    x4 += m; y4 += n; z4 += k;
    x5 += m; y5 += n; z5 += k;
    x6 += m; y6 += n; z6 += k;
    x7 += m; y7 += n; z7 += k;
    x8 += m; y8 += n; z8 += k;
}

void Cube::scaleX(int factor) {
    x1 *= factor;
    x2 *= factor;
    x3 *= factor;
    x4 *= factor;
    x5 *= factor;
    x6 *= factor;
    x7 *= factor;
    x8 *= factor;
}

void Cube::scaleY(int factor) {
    y1 *= factor;
    y2 *= factor;
    y3 *= factor;
    y4 *= factor;
    y5 *= factor;
    y6 *= factor;
    y7 *= factor;
    y8 *= factor;
}

void Cube::scaleZ(int factor) {
    z1 *= factor;
    z2 *= factor;
    z3 *= factor;
    z4 *= factor;
    z5 *= factor;
    z6 *= factor;
    z7 *= factor;
    z8 *= factor;
}

void Cube::scale(int factor) {
    x1 /= factor; y1 /= factor; z1 /= factor;
    x2 /= factor; y2 /= factor; z2 /= factor;
    x3 /= factor; y3 /= factor; z3 /= factor;
    x4 /= factor; y4 /= factor; z4 /= factor;
    x5 /= factor; y5 /= factor; z5 /= factor;
    x6 /= factor; y6 /= factor; z6 /= factor;
    x7 /= factor; y7 /= factor; z7 /= factor;
    x8 /= factor; y8 /= factor; z8 /= factor;
}
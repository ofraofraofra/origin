#pragma once
#include "Shape.h"

class Cube : public Shape {
public:
    Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
    double getArea() const override;
    double getVolume() const override;
    void shift(int m, int n, int k) override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scaleZ(int factor) override;
    void scale(int factor) override;
private:
    int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8;
};
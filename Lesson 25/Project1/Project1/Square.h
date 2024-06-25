#pragma once
#include "Shape.h"

class Square : public Shape {
public:
    Square(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
    double getArea() const override;
    double getVolume() const override;
    void shift(int m, int n, int k) override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scaleZ(int factor) override;
    void scale(int factor) override;
private:
    int x1, y1, x2, y2, x3, y3, x4, y4;
};
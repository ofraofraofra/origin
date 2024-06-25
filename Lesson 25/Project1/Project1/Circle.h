#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int _x1, int _y1, double _radius);
    double getArea() const override;
    double getVolume() const override;
    void shift(int m, int n, int k) override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scaleZ(int factor) override;
    void scale(int factor) override;
private:
    int x1, y1;
    double radius;
};

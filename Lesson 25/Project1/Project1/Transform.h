#pragma once
#include "Shape.h"

class Transform {
public:
    Transform(Shape* sh);
    void shift(int m, int n, int k);
    void scaleX(int factor);
    void scaleY(int factor);
    void scaleZ(int factor);
    void scale(int factor);

private:
    Shape* shape;
};
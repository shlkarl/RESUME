#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

class Rectangle : public Shape
{
private:
    double a;
    double b;
public:
    Rectangle();
    Rectangle(double A, double B);
    Rectangle(const Rectangle &Other);
    ~Rectangle();
    virtual void draw();
    void print();
};

#endif
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
private:
    double area;
public:
    Shape();
    Shape(double Area);
    Shape(const Shape &Other);
    virtual ~Shape();
    virtual void draw();
    void print();
    double GetArea();
};

#endif
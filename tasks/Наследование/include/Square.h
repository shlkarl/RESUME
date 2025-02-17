#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

class Square: public Rectangle
{
public:
    Square();
    Square(double C);
    Square(const Square &Other);
    ~Square();
    virtual void draw();
    void print();
};

#endif
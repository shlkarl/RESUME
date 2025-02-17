#include "Shape.h"

Shape::Shape() : area(0)
{
    std::cout << "Constructor Shape() at " << this << " was called"
              << std::endl;
}

Shape::Shape(double Area) : area(Area)
{
    std::cout << "Constructor Shape(double Area) at " << this << " was called"
              << std::endl;
}

Shape::Shape(const Shape &Other) : area(Other.area)
{
    std::cout << "Constructor Shape(const Shape &Other) at " << this
              << " was called" << std::endl;
}

Shape::~Shape()
{
    std::cout << "Destructor ~Shape() at " << this << " was called"
              << std::endl;
}

void Shape::draw()
{
    std::cout << "Shape::draw()" << std::endl;
}

void Shape::print()
{
    std::cout << "Shape::print()" << std::endl;
}

double Shape::GetArea()
{
    return area;
}
#include "Rectangle.h"

Rectangle::Rectangle() : a(0), b(0)
{
    std::cout << "Constructor Rectangle() at " << this << " was called"
              << std::endl;
}

Rectangle::Rectangle(double A, double B) : Shape(A * B), a(A), b(B)
{
    std::cout << "Constructor Rectangle(double A, double B) at " << this
              << " was called" << std::endl;
}

Rectangle::Rectangle(const Rectangle &Other)
    : Shape(Other), a(Other.a), b(Other.b)
{
    std::cout << "Constructor Rectangle(const Rectangle &Other) at " << this
              << " was called" << std::endl;
}

Rectangle::~Rectangle()
{
    std::cout << "Destructor ~Rectangle() at " << this << " was called"
              << std::endl;
}

void Rectangle::draw()
{
    std::cout << "Rectangle::draw()" << std::endl;
}

void Rectangle::print()
{
    std::cout << "Rectangle::print()" << std::endl;
}
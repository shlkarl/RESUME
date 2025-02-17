#include "Square.h"

Square::Square()
{
    std::cout << "Constructor Square() at " << this << " was called"
              << std::endl;
}

Square::Square(double C) : Rectangle(C, C)
{
    std::cout << "Constructor Square(double C) at " << this << " was called"
              << std::endl;
}

Square::Square(const Square &Other) : Rectangle(Other)
{
    std::cout << "Constructor Square(const Square &Other) at " << this
              << " was called" << std::endl;
}

Square::~Square()
{
    std::cout << "Destructor ~Square() at " << this << " was called"
              << std::endl;
}

void Square::draw()
{
    std::cout << "Square::draw()" << std::endl;
}

void Square::print()
{
    std::cout << "Square::print()" << std::endl;
}
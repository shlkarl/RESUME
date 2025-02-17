// Aitov A.V.
// 3431104/00001
// Task 8

// inheritance. polymorphism

#include <iostream>

#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"

void Draw1(Shape S);
void Draw2(Shape *S);
void Draw3(Shape &S);
void printHeader(void);

int main(void)
{
    printHeader();


    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Shape shape1" << std::endl;
    Shape shape1;
    std::cout << "Area: " << shape1.GetArea() << std::endl;
    Draw1(shape1);
    Draw2(&shape1);
    Draw3(shape1);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Shape shape2(10)" << std::endl;
    Shape shape2(10);
    std::cout << "Area: " << shape2.GetArea() << std::endl;
    Draw1(shape2);
    Draw2(&shape2);
    Draw3(shape2);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Shape shape3(shape2)" << std::endl;
    Shape shape3(shape2);
    std::cout << "Area: " << shape3.GetArea() << std::endl;
    Draw1(shape3);
    Draw2(&shape3);
    Draw3(shape3);


    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Rectangle rectangle1" << std::endl;
    Rectangle rectangle1;
    std::cout << "Area: " << rectangle1.GetArea() << std::endl;
    Draw1(rectangle1);
    Draw2(&rectangle1);
    Draw3(rectangle1);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Rectangle rectangle2(3, 4)" << std::endl;
    Rectangle rectangle2(3, 4);
    std::cout << "Area: " << rectangle2.GetArea() << std::endl;
    Draw1(rectangle2);
    Draw2(&rectangle2);
    Draw3(rectangle2);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Rectangle rectangle3(rectangle2)" << std::endl;
    Rectangle rectangle3(rectangle2);
    std::cout << "Area: " << rectangle3.GetArea() << std::endl;
    Draw1(rectangle3);
    Draw2(&rectangle3);
    Draw3(rectangle3);


    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Square square1" << std::endl;
    Square square1;
    std::cout << "Area: " << square1.GetArea() << std::endl;
    Draw1(square1);
    Draw2(&square1);
    Draw3(square1);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Square square2(5)" << std::endl;
    Square square2(5);
    std::cout << "Area: " << square2.GetArea() << std::endl;
    Draw1(square2);
    Draw2(&square2);
    Draw3(square2);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Square square3(square2)" << std::endl;
    Square square3(square2);
    std::cout << "Area: " << square3.GetArea() << std::endl;
    Draw1(square3);
    Draw2(&square3);
    Draw3(square3);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Dynamic memory allocation (destructors are virtual)"
              << std::endl << std::endl;

    std::cout << "Shape *ptr1 = new Rectangle(6, 66)" << std::endl;
    Shape *ptr1 = new Rectangle(6, 66);
    std::cout << std::endl;

    std::cout << "Shape *ptr2 = new Square(square3)" << std::endl;
    Shape *ptr2 = new Square(square3);
    std::cout << std::endl;

    std::cout << "delete ptr1" << std::endl;
    delete ptr1;
    std::cout << std::endl;

    std::cout << "delete ptr2" << std::endl;
    delete ptr2;

    std::cout << "-----------------------------------------------" << std::endl;

    return 0;
}

void Draw1(Shape S)
{
    std::cout << "Draw1:" << std::endl;
    S.draw();
    S.print();
}

void Draw2(Shape *S)
{
    std::cout << "Draw2:" << std::endl;
    S->Shape::draw();
    S->draw();
    S->print();
}

void Draw3(Shape &S)
{
    std::cout << "Draw3:" << std::endl;
    S.draw();
    S.print();
}

void printHeader(void)
{
    std::cout << "Aitov A.V.\n"
              << "3431104/00001\n"
              << "Task 8\n\n\n";
}
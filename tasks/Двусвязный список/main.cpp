// Aitov A.V.
// 3431104/00001
// Task 7

// realization of doubly linked list

#include <fstream>
#include <iostream>

#include "List.h"

// generate anonymous object
List generateObj(const List &Lst);

void printHeader(void);

int main(void)
{
    printHeader();
//---------------------------------------------------------------------------//
    // FILES
    // INPUT
    std::ifstream inputFile("input/input.txt");
    if(!inputFile.is_open())
    {
        std::cerr << "ERROR OPENING INPUT FILE" << std::endl;
    }
    // OUTPUT
    std::ofstream outputFile("output/output.txt");
    if(!outputFile.is_open())
    {
        std::cerr << "ERROR OPENING OUTPUT FILE" << std::endl;
    }
//---------------------------------------------------------------------------//
    // FIRST LIST
    List first;
    if (first.IsEmpty())
    {
        std::cout << "List 'first' is empty" << std::endl;
    }
    else
    {
        std::cout << "List 'first' is not empty" << std::endl;
    }
    std::cout << "List 'first'" << std::endl;
    first.Print();
    std::cout << "List 'first'" << std::endl;
    first.PrintReverse();

    std::cout << "Reading data from file \"input.txt\" to List 'first'..."
              << std::endl << std::endl;
    inputFile >> first;
    inputFile.close();

    if (first.IsEmpty())
    {
        std::cout << "List 'first' is empty" << std::endl;
    }
    else
    {
        std::cout << "List 'first' is not empty" << std::endl;
    }
    std::cout << "List 'first'" << std::endl;
    first.Print();
    std::cout << "List 'first'" << std::endl;
    first.PrintReverse();

    std::cout << "Deleting first element with value 6..." << std::endl;
    first.Delete(6);
    std::cout << "List 'first'" << std::endl;
    first.Print();
    std::cout << "List 'first'" << std::endl;
    first.PrintReverse();

    std::cout << "Deleting all elements with value 6..." << std::endl;
    first.DeleteAllWithVal(6);
    std::cout << "List 'first'" << std::endl;
    first.Print();
    std::cout << "List 'first'" << std::endl;
    first.PrintReverse();

    std::cout << "Clearing List 'first'..." << std::endl;
    first.Clear();

    if (first.IsEmpty())
    {
        std::cout << "List 'first' is empty" << std::endl;
    }
    else
    {
        std::cout << "List 'first' is not empty" << std::endl;
    }
    std::cout << "List 'first'" << std::endl;
    first.Print();
    std::cout << "List 'first'" << std::endl;
    first.PrintReverse();

//---------------------------------------------------------------------------//
    // SECOND LIST
    List second(101);
    if (second.IsEmpty())
    {
        std::cout << "List 'second' is empty" << std::endl;
    }
    else
    {
        std::cout << "List 'second' is not empty" << std::endl;
    }
    std::cout << "List 'second'" << std::endl;
    second.Print();
    std::cout << "List 'second'" << std::endl;
    second.PrintReverse();

    std::cout << "Add some elements to list " << "with Add()...";
    second.Add(4);
    second.Add(2);
    std::cout << "List 'second'" << std::endl;
    second.Print();
    std::cout << "List 'second'" << std::endl;
    second.PrintReverse();

    std::cout << "Add 3, 2, 1 before Pos=1 to list " << "with AddBefore()...";
    second.AddBefore(3, 1);
    second.AddBefore(2, 1);
    second.AddBefore(1, 1);
    std::cout << "List 'second'" << std::endl;
    second.Print();
    std::cout << "List 'second'" << std::endl;
    second.PrintReverse();
    std::cout << "Add 7, 6, 5 after Pos=5 to list " << "with AddBefore()...";
    second.AddAfter(7, 5);
    second.AddAfter(6, 5);
    second.AddAfter(5, 5);
    std::cout << "List 'second'" << std::endl;
    second.Print();
    std::cout << "List 'second'" << std::endl;
    second.PrintReverse();

//---------------------------------------------------------------------------//
    // COPIED
    std::cout << "Copying List 'second' to List 'third':"
              << std::endl << std::endl;
    List third(second);
    std::cout << "List 'third'" << std::endl;
    third.Print();
    std::cout << "List 'third'" << std::endl;
    third.PrintReverse();

    std::cout << "Copying List 'third' to List 'fourth':"
              << std::endl << std::endl;
    List fourth;
    fourth = third;
    std::cout << "List 'fourth'" << std::endl;
    fourth.Print();
    std::cout << "List 'fourth'" << std::endl;
    fourth.PrintReverse();

    std::cout << "Moving anonymous object to List 'fifth':"
              << std::endl << std::endl;
    List fifth(std::move(generateObj(fourth)));
    std::cout << "List 'fifth'" << std::endl;
    fifth.Print();
    std::cout << "List 'fifth'" << std::endl;
    fifth.PrintReverse();

    std::cout << "Moving anonymous object to List 'sixth':"
              << std::endl << std::endl;
    List sixth(fifth);
    sixth = generateObj(fifth);
    std::cout << "List 'sixth'" << std::endl;
    sixth.Print();
    std::cout << "List 'sixth'" << std::endl;
    sixth.PrintReverse();

    std::cout << "Writing List 'sixth' to output/output.txt..."
              << std::endl << std::endl;
    outputFile << sixth;

    inputFile.close();
    outputFile.close();

    return 0;
}


List generateObj(const List &Lst)
{
    return List(Lst);
}

void printHeader(void)
{
    std::cout << "Aitov A.V.\n"
              << "3431104/00001\n"
              << "Task 7\n\n\n";
}
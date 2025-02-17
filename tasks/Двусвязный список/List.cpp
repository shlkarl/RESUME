// doubly linked list
#include "List.h"


List::List() : Head(), Tail()
{
    Head.Prev = Tail.Next = nullptr;
    Head.Next = &Tail;
    Tail.Prev = &Head;

    Head.Data = 1;
    Tail.Data = 0;

    std::cout << "Constructor List() at " << this << " was called"
              << std::endl << std::endl;
}

List::List(int Val) : List()
{
    Add(Val);

    std::cout << "Constructor List(int Val) at " << this << " was called"
              << std::endl << std::endl;
}

List::List(const List &Lst) : List()
{
    ListNode *Current = Lst.Head.Next;
    while (Current != &Lst.Tail)
    {
        Add(Current->Data);
        Current = Current->Next;
    }

    std::cout << "Constructor List(const List &Lst) at " << this
              << " was called" << std::endl << std::endl;
}

List::List(List &&Lst) : List()
{
    // move
    Head.Next = Lst.Head.Next;
    Head.Next->Prev = &Head;
    Tail.Prev = Lst.Tail.Prev;
    Tail.Prev->Next = &Tail;

    // clear temporary object
    Lst.Head.Next = &Lst.Tail;
    Lst.Tail.Prev = &Lst.Head;

    std::cout << "Constructor List(List &&Lst) at " << this << " was called"
              << std::endl << std::endl;
}

List::~List()
{
    Clear();

    std::cout << "Destructor ~List() at " << this << " was called"
              << std::endl << std::endl;
}

List& List::operator=(const List &Lst)
{
    if (this != &Lst)
    {
        Clear();
        ListNode *Current = Lst.Head.Next;
        while (Current != &Lst.Tail)
        {
            Add(Current->Data);
            Current = Current->Next;
        }
    }

    std::cout << "Operator=(const List &Lst) at " << this << " was called"
              << std::endl << std::endl;

    return *this;
}

List& List::operator=(List &&Lst)
{
    if (this != &Lst)
    {
        Clear();
        // move
        Head.Next = Lst.Head.Next;
        Head.Next->Prev = &Head;
        Tail.Prev = Lst.Tail.Prev;
        Tail.Prev->Next = &Tail;

        // clear temporary object
        Lst.Head.Next = &Lst.Tail;
        Lst.Tail.Prev = &Lst.Head;
    }

    std::cout << "Operator=(List &&Lst) at " << this << " was called"
              << std::endl << std::endl;

    return *this;
}

void List::Add(int Val)
{
    ListNode *Elem = new ListNode;
    Elem->Data = Val;
    Elem->Next = &Tail;
    Elem->Prev = Tail.Prev;
    Tail.Prev->Next = Elem;
    Tail.Prev = Elem;
}

void List::AddAfter(int Val, UINT Pos)
{
    ListNode *Elem = new ListNode;
    Elem->Data = Val;
    Elem->Next = Head.Next;

    for (UINT i = 0; i <= Pos; i++)
    {
        if (Elem->Next == &Tail)
        {
            break;
        }
        Elem->Next = Elem->Next->Next;
    }
    Elem->Prev = Elem->Next->Prev;
    Elem->Prev->Next = Elem;
    Elem->Next->Prev = Elem;
}

void List::AddBefore(int Val, UINT Pos)
{
    ListNode *Elem = new ListNode;
    Elem->Data = Val;
    Elem->Next = Head.Next;

    for (UINT i = 0; i < Pos; i++)
    {
        if (Elem->Next == &Tail)
        {
            break;
        }
        Elem->Next = Elem->Next->Next;
    }
    Elem->Prev = Elem->Next->Prev;
    Elem->Prev->Next = Elem;
    Elem->Next->Prev = Elem;
}

void List::Print()
{
    ListNode *Current = Head.Next;
    int pos = 0;
    std::cout << "List:" << std::endl;
    while (Current != &Tail)
    {
        std::cout << pos++ << ": " << Current->Data << std::endl;
        Current = Current->Next;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Total: " << pos << std::endl << std::endl;
}

void List::PrintReverse()
{
    ListNode *Current = Tail.Prev;
    int pos = 0;
    std::cout << "List in reversed order:" << std::endl;
    while (Current != &Head)
    {
        std::cout << --pos << ": " << Current->Data << std::endl;
        Current = Current->Prev;
    }
    std::cout << "------------" << std::endl;
    std::cout << "Total: " << -pos << std::endl << std::endl;
}

void List::Delete(int Val)
{
    ListNode *Current = Head.Next;
    while (Current != &Tail)
    {
        if (Current->Data == Val)
        {
            Current->Next->Prev = Current->Prev;
            Current->Prev->Next = Current->Next;
            delete Current;
            break;
        }
        Current = Current->Next;
    }

}

void List::DeleteAllWithVal(int Val)
{
    ListNode *Current = Head.Next;
    ListNode *Tmp = Current;
    while (Current != &Tail)
    {
        Current = Current->Next;
        if (Tmp->Data == Val)
        {
            Tmp->Next->Prev = Tmp->Prev;
            Tmp->Prev->Next = Tmp->Next;
            delete Tmp;
        }
        Tmp = Current;
    }
}

void List::Clear()
{
    while(Tail.Prev != &Head)
    {
        ListNode *Tmp = Tail.Prev->Prev;
        delete Tail.Prev;
        Tail.Prev = Tmp;
    }
    Head.Next = &Tail;
    std::cout << "List at " << this << " cleared!" << std::endl << std::endl;
}

bool List::IsEmpty()
{
    return Head.Next == &Tail;
}

std::ofstream& operator << (std::ofstream& File, List &Lst)
{
    ListNode *Current = Lst.Head.Next;
    while (Current != &Lst.Tail)
    {
        if(File.fail())
        {
            std::cerr << "ERROR WRITING TO FILE " << &File << std::endl;
        }
        File << Current->Data << std::endl;
        Current = Current->Next;
    }

    return File;
}

std::ifstream& operator >> (std::ifstream& File, List &Lst)
{
    int elem;
    while(!File.eof())
    {
        File >> elem;
        if(File.fail())
        {
            std::cerr << "ERROR READING FROM FILE " << &File << std::endl;
            break;
        }
        Lst.Add(elem);
    }

    return File;
}
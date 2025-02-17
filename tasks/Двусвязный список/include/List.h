// doubly linked list

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

typedef unsigned int UINT;

struct ListNode
{
    int Data;
    ListNode *Next;
    ListNode *Prev;
};

class List
{
    ListNode Head;
    ListNode Tail;
public:
    List();
    List(int Val);
    List(const List &Lst);
    List(List &&Lst);
    ~List();
    List& operator = (const List &Lst);
    List& operator = (List &&Lst);
    void Add(int Val);
    void AddAfter(int Val, UINT Pos);
    void AddBefore(int Val, UINT Pos);
    void Print();
    void PrintReverse();
    void Delete(int Val);
    void DeleteAllWithVal(int Val);
    void Clear();
    bool IsEmpty();
    friend std::ofstream& operator << (std::ofstream& File, List &Lst);
};

std::ifstream& operator >> (std::ifstream& File, List &Lst);

#endif
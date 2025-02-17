// Aitov A.V.
// 3431104/00001
// Task 4

// Simple implementation of quicksort algorithm, using templates and
// function pointers.

#include <iostream>
#include <cstdlib>  // srand(), rand()
#include <ctime>    // time()

// set the size of the arrays
#define ARR_SIZE 50
// #define INT_ARR_SIZE
// #define DBL_ARR_SIZE

// recursive quicksort algorithm
template<typename T>
void sort(T*, int, bool (*)(T, T));

// divides an array into two parts and returns position of the pivot
template<typename T>
int partition(T*, int, bool (*)(T, T));

// swaps two numbers
template<typename T>
void swap(T&, T&);

// compares two numbers
template<typename T>
bool greater(T, T);

// compares two numbers
template<typename T>
bool less(T, T);

// initializes array with 'random' numbers
template<typename T>
void initArray(T*, int);

// prints array
template<typename T>
void printArray(T*, int);

// prints header
void printHeader(void);


int main(void)
{
    // header
    printHeader();

    // initializing arrays
    int intArr[ARR_SIZE] = {0};
    double dblArr[ARR_SIZE] = {0};

    initArray(intArr, ARR_SIZE);
    initArray(dblArr, ARR_SIZE);

    // printing initial intArr
    std::cout << "Initial intArr:\n";
    printArray(intArr, ARR_SIZE);

    // sorting #1
    sort(intArr, ARR_SIZE, greater);

    std::cout << "intArr sorted in ascending order:\n";
    printArray(intArr, ARR_SIZE);

    // sorting #2
    sort(intArr, ARR_SIZE, less);

    std::cout << "intArr sorted in descending order:\n";
    printArray(intArr, ARR_SIZE);


    // printing initial dblArr
    std::cout << "Initial dblArr:\n";
    printArray(dblArr, ARR_SIZE);

    // sorting #3
    sort(dblArr, ARR_SIZE, greater);

    std::cout << "dblArr sorted in ascending order:\n";
    printArray(dblArr, ARR_SIZE);

    // sorting #4
    sort(dblArr, ARR_SIZE, less);

    std::cout << "dblArr sorted in descending order:\n";
    printArray(dblArr, ARR_SIZE);

    return 0;
}


template<typename T>
void sort(T *Arr, int size, bool (*CmpFun)(T, T))
{
    if(size > 0)
    {
        int p_index = partition(Arr, size, CmpFun);
        sort(Arr, p_index, CmpFun);
        sort(Arr + p_index + 1, size - p_index - 1, CmpFun);
    }
}

template<typename T>
int partition(T *Arr, int size, bool (*CmpFun)(T, T))
{
    int pos = 0;
    for(int i = 0; i < size; i++)
    {
        if(CmpFun(Arr[size - 1], Arr[i]))
        {
            swap(Arr[i], Arr[pos]);
            pos++;
        }
    }
    swap(Arr[size - 1], Arr[pos]);
    return pos;
}

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
bool greater(T a, T b)
{
    return a > b;
}

template<typename T>
bool less(T a, T b)
{
    return a < b;
}

template<typename T>
void initArray(T *Arr, int size)
{
    srand(static_cast<unsigned int>(time(0)));

    for(int i = 0; i < size; i++)
    {
        Arr[i] = static_cast<double>(rand() % 100000) / 1000;
    }
}

template<typename T>
void printArray(T *Arr, int size)
{
    std::cout << "[";
    for(int i = 0; i < size - 1; i++)
    {
        std::cout << Arr[i] << ", ";
    }
    std::cout << Arr[size - 1] << "]";
    std::cout << std::endl << std::endl;
}

void printHeader(void)
{
    std::cout << "Aitov A.V.\n3431104/00001\nTask 4\n\n";
}
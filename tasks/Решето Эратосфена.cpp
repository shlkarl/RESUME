// Aitov A.V.
// 3431104/00001

// Программа для получения простого числа по порядковому номеру
// c помощью решета Эратосфeна.(1 -> 2; 2 -> 3; 3 -> 5;...)

#include <iostream>
#include <cmath> // for sqrt()

#define MAX_SIEVE_SIZE 10000
#define MAX_INDEX 1229
#define MIN_INDEX 1

typedef unsigned int UINT;


UINT getPrimeNumber(UINT indexOfPrimeNumber);
void fillSieve(UINT* sieve);
void crossOutMultiples(UINT* sieve);
bool notCrossed(UINT i);
void crossOutMultiplesOf(UINT i, UINT* sieve);
UINT findPrimeNumberBy(UINT indexOfPrimeNumber, UINT* sieve);

UINT getUserInput(void);
int getInteger();
bool invalid(UINT i);
void resetFlags(void);
void printHeader(void);

int main(void)
{
    printHeader();

    UINT indexOfPrimeNumber = getUserInput();

    int result = getPrimeNumber(indexOfPrimeNumber);

    std::cout << "getPrimeNumber("
              << indexOfPrimeNumber
              << ") = "
              << result
              << std::endl;

    while(1);
}

UINT getUserInput(void)
{
    int input = getInteger();

    while (invalid(input))
    {
        resetFlags();
        input = getInteger();
    }
    return input;
}

int getInteger(void)
{
    UINT input = 0;
    std::cout << "Enter integer [1, 1229]: ";
    std::cin >> input;
    return input;
}

bool invalid(UINT i)
{
    return (i > MAX_INDEX || i < MIN_INDEX);
}

void resetFlags(void)
{
    if(std::cin.fail())
        std::cin.clear();
    std::cin.ignore(1024, '\n');
}

UINT getPrimeNumber(UINT indexOfPrimeNumber)
{
    UINT sieve[MAX_SIEVE_SIZE] = {0};

    fillSieve(sieve);
    crossOutMultiples(sieve);
    UINT result = findPrimeNumberBy(indexOfPrimeNumber, sieve);

    return result;
}

void fillSieve(UINT* sieve)
{
    for(UINT i = 0; i < MAX_SIEVE_SIZE; i++)
        sieve[i] = i;
}

void crossOutMultiples(UINT* sieve)
{
    for(UINT i = 2; i < sqrt(MAX_SIEVE_SIZE); i++)
        if(notCrossed(sieve[i]))
            crossOutMultiplesOf(i, sieve);
}

bool notCrossed(UINT i)
{
    return i;
}

void crossOutMultiplesOf(UINT i, UINT* sieve)
{
    for(UINT j = i * i; j < MAX_SIEVE_SIZE; j += i)
        sieve[j] = 0;
}

UINT findPrimeNumberBy(UINT indexOfPrimNumber, UINT* sieve)
{
    UINT primeNumberCounter = 0;
    UINT result = 0;
    for(UINT i = 2; primeNumberCounter != indexOfPrimNumber; i++)
        if(notCrossed(sieve[i]))
        {
            result = sieve[i];
            primeNumberCounter++;
        }
    return result;
}


void printHeader(void)
{
    std::cout << "Aitov A.V.\n"
              << "3431104/00001\n"
              << "Task 3\n\n";
}
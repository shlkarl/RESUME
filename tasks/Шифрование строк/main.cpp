// Aitov A.V.
// 3431104/00001
// Task 6

// this program 'encrypts' strings using XOR and compares them

#include <cstring>  // for strcmp(), strlen()
#include <iostream> // for cout
#include <string>   // for string, .length()
#include "Str.h"    // for StrCrypt();


void printHeader(void);

int main(void)
{
    printHeader();

    char key = 'M';
    // ------------------------------------------------------------------------

    // C-style strings

    char cSrcStr[] = "I M A G I N E";
    int cStrLen = static_cast<int>(strlen(cSrcStr));

    char* cCryptStr = StrCrypt(cSrcStr, cStrLen, key);
    char* cCryptStr2 = StrCrypt(cCryptStr, cStrLen, key);

    std::cout << "Initial C-style string: " << std::endl
              << "\"" << cSrcStr << "\"" << std::endl << std::endl;

    std::cout << "Double-XOR-encrypted C-style string: " << std::endl
              << "\"" << cCryptStr2 << "\"" << std::endl << std::endl;

    if(!std::strcmp(cSrcStr, cCryptStr2))
    {
        std::cout << "C-style strings are equal!" << std::endl;
    }
    else
    {
        std::cout << "C-style strings are different." << std::endl;
    }

    delete [] cCryptStr;
    delete [] cCryptStr2;

    std::cout << "--------------------------------"
              << std::endl << std::endl;
    // ------------------------------------------------------------------------

    // CPP-style strings

    std::string cppSrcStr = "L O V E C O D I N G";
    int cppStrLen = static_cast<int>(cppSrcStr.length());

    std::string cppCryptStr = StrCrypt(cppSrcStr, cppStrLen, key);
    std::string cppCryptStr2 = StrCrypt(cppCryptStr, cppStrLen, key);

    std::cout << "Initial CPP-style string: " << std::endl
              << "\"" << cppSrcStr << "\"" << std::endl << std::endl;

    std::cout << "Double-XOR-encrypted CPP-style string: " << std::endl
              << "\"" << cppCryptStr2 << "\"" << std::endl << std::endl;

    if(cppSrcStr == cppCryptStr2)
    {
        std::cout << "CPP-style strings are equal!" << std::endl;
    }
    else
    {
        std::cout << "CPP-style strings are different." << std::endl;
    }

    std::cout << "--------------------------------"
              << std::endl << std::endl;


    return 0;
}


void printHeader(void)
{
    std::cout << "Aitov A.V." << std::endl
              << "3431104/00001" << std::endl
              << "Task 6" << std::endl << std::endl;
}
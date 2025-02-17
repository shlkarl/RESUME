#include <cstring>
#include <string>
#include "Str.h"


char* StrCrypt(char* srcStr, int length, char key)
{
    char *resStr = new char[length + 1];
    std::memset(resStr, 0, length + 1);

    for(int i = 0; i < length; i++)
    {
        resStr[i] = srcStr[i] ^ key;
    }

    return resStr;
}

std::string StrCrypt(std::string& srcStr, int length, char key)
{
    std::string resStr = srcStr;

    for(int i = 0; i < length; i++)
    {
        resStr[i] = srcStr[i] ^ key;
    }

    return resStr;
}
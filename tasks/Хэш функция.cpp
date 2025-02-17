// Aitov A.V.
// 3431104/00001
// Task 5

// this program restore a password by hash using 'brute force'

// password = WMAA4

#include <iostream>
#include <iomanip>

#define MAX_LENGTH 5
#define AMOUNT_OF_VARS 26

typedef unsigned int UINT;


// generate hash
UINT Hash(const char*, int);

bool RestorePasswd(UINT, int, char*, int*);

void printData(const char*, int, UINT, int, bool);

// get hash from pool
UINT getHash(int);

void printHeader(void);

bool getUserInput(void);


int main(void)
{
    printHeader();

    char passwd[MAX_LENGTH + 1] = "";
    int length = 0;

    // my variant
    UINT myHash = 0x014FC00C;

    std::cout << "Restoring password..." << std::endl << std::endl;

    bool isRestored = RestorePasswd(myHash, MAX_LENGTH, passwd, &length);
    printData(passwd, length, myHash, 20, isRestored);


    // all variants
    std::cout << "RESTORE ALL PASSWORDS" << std::endl;
    if(!getUserInput())
    {
        return 0;
    }

    std::cout << std::endl << "Restoring all passwords..."
              << std::endl << std::endl;

    for(int i = 0; i < AMOUNT_OF_VARS; i++)
    {
        UINT hashValue = getHash(i);

        isRestored = RestorePasswd(hashValue, MAX_LENGTH, passwd, &length);
        printData(passwd, length, hashValue, i + 1, isRestored);
    }

    return 0;
}


UINT Hash(const char* passwd, int len)
{
    UINT res = 0;

    for(int i = 0; i < len; i++)
    {
        res += passwd[i];
    }

    return (res << 16) ^ ((passwd[0] << 14) +
           ((passwd[len-1] ^ len) >> (len >> 1)));
}

bool RestorePasswd(UINT hashValue, int maxLength,
                   char* result, int* resLength)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int power = sizeof(alphabet) - 1;

    int maxIter = power;

    for(int strLen = 1; strLen <= maxLength; strLen++)
    {
        for(int i = 0; i < maxIter; i++)
        {
            for(int j = 0, div = 1; j < strLen; j++, div *= power)
            {
                result[j] = alphabet[(i / div) % power];
            }
            if(Hash(result, strLen) == hashValue)
            {
                *resLength = strLen;
                return true;
            }
        }
        maxIter *= power;
    }

    return false;
}

void printData(const char* passwd, int len, UINT hashValue, int var, bool flag)
{
    std::cout << "Variant: " << std::dec << var << std::endl;

    if(flag)
        std::cout << "Password: " << passwd << std::endl;
    else
        std::cout << "Password: " << "NOT CRACKED!" << std::endl;

    std::cout << "Length: " << len << std::endl
              << "Hash: 0x" << std::setfill('0') << std::setw(8)
              << std::uppercase << std::hex << hashValue
              << std::endl << std::endl;
}

UINT getHash(int var)
{
    UINT pool[AMOUNT_OF_VARS] = {0x0155C00D, 0x0158C00C, 0x015BC00C,
                                 0x0145C00F, 0x0161000D, 0x0190C015,
                                 0x0140800D, 0x014A000D, 0x0141C00D,
                                 0x0170C011, 0x014CC00C, 0x0171C00F,
                                 0x019AC012, 0x0155400D, 0x0175C010,
                                 0x01728011, 0x01928015, 0x01854012,
                                 0x0152400D, 0x014FC00C, 0x01870012,
                                 0x0164C015, 0x01644012, 0x01948014,
                                 0x016CC012, 0x019C8015};

    return pool[var];
}

void printHeader(void)
{
    std::cout << "Aitov A.V." << std::endl
              << "3431104/00001" << std::endl
              << "Task 5" << std::endl << std::endl;
}

bool getUserInput(void)
{
    char answer;
    do
    {
        std::cout << "(Y/N)?" << std::endl;
        std::cin >> answer;
        std::cout << std::endl;
        std::cin.ignore(1111111, '\n');
    }
    while (answer != 'Y' && answer != 'y' &&
           answer != 'N' && answer != 'n');

    if(answer == 'Y' || answer == 'y')
        return true;

    return false;
}
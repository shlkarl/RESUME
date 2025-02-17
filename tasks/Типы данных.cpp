// Вывод размеры стандартных типов данных (с различными спецификаторами)
// и указателей.

#include <iostream>

int main()
{
    std::cout << "Aitov A.V.\n";
    std::cout << "3431104/00001\n";
    std::cout << "Task 1\n\n";

    std::cout << "Data types:" << std::endl << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "signed int: " << sizeof(signed int) << " bytes" << std::endl;
    std::cout << "signed long: " << sizeof(signed long) << " bytes" << std::endl;
    std::cout << "signed long long: " << sizeof(signed long long) << " bytes" << std::endl;
    std::cout << "signed short: " << sizeof(signed short) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "unsigned long: " << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "unsigned long long: " << sizeof(unsigned long long) << " bytes" << std::endl;
    std::cout << "unsigned short: " << sizeof(unsigned short) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "signed char: " << sizeof(signed char) << " bytes" << std::endl;
    std::cout << "unsigned char: " << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "wchar_t: " << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Pointers:" << std::endl << std::endl;

    std::cout << "int*: " << sizeof(int*) << " bytes" << std::endl;
    std::cout << "long*: " << sizeof(long*) << " bytes" << std::endl;
    std::cout << "long long*: " << sizeof(long long*) << " bytes" << std::endl;
    std::cout << "short*: " << sizeof(short*) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "signed int*: " << sizeof(signed int*) << " bytes" << std::endl;
    std::cout << "signed long*: " << sizeof(signed long*) << " bytes" << std::endl;
    std::cout << "signed long long*: " << sizeof(signed long long*) << " bytes" << std::endl;
    std::cout << "signed short*: " << sizeof(signed short*) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "char*: " << sizeof(char*) << " bytes" << std::endl;
    std::cout << "signed char*: " << sizeof(signed char*) << " bytes" << std::endl;
    std::cout << "unsigned char*: " << sizeof(unsigned char*) << " bytes" << std::endl;
    std::cout << "wchar_t*: " << sizeof(wchar_t*) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "bool*: " << sizeof(bool*) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "float*: " << sizeof(float*) << " bytes" << std::endl;
    std::cout << "double*: " << sizeof(double*) << " bytes" << std::endl;
    std::cout << "long double*: " << sizeof(long double*) << " bytes" << std::endl;
    std::cout << std::endl;

    std::cout << "void*: " << sizeof(void*) << " bytes" << std::endl;


while(1);
    return 0;

}

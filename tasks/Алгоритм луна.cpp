// Aitov A.V.
// 3431104/00001

// Программа для проверки 16-значного номера карты
// по упрощенному алгоритму Луна

#include <iostream>
#define LENGTH 16

bool isValidCardNumber(int *);

int main(void)
{
    std::cout << "Aitov A.V.\n3431104/00001\nTask 2\n\n";

    int cardNum[LENGTH] = {0};
    int button = 0;

    do
    {
        // 'n' --> n;
        //считываем символ(char) и вычитаем из него '0' (код - 48)
        //т.е. {'0','1',...,'9'} - '0' = {48,49,...,57} - 48 = {0,1,...,9}
        std::cout << "Enter card number(without spaces): ";
        for(int i = 0; i < LENGTH; i++)
            cardNum[i] = std::cin.get() - '0';

        if(isValidCardNumber(cardNum))
            std::cout << "Card number is valid.\n\n";
        else
            std::cout << "Card number is invalid.\n\n";

        std::cout << "Press ENTER to continue or ANY OTHER KEY + ENTER to quit\n";
        std::cin.ignore(32767, '\n');
        button = std::cin.get();
    }
    while(!(button - '\n'));

    return 0;
}

bool isValidCardNumber(int *number)
{
    int sum = 0;
    for(int i = 0; i < LENGTH; i++)
    {
        if(i & 0x1)
            sum += number[i];
        else
            sum += (number[i] << 1) % 10 + (number[i] << 1) / 10;   
    }
    return !(sum % 10);
}
#include "Header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str = "Привет парни! Как вы?";
    const int target_len = 100; // указываем нужную нам длину 

    string output;
    switch (stretch(output, str, target_len))
    {
    case 0:
        cout << str << endl;
        cout << output << endl;
        break;

    case 1:
        cout << "Заданная длина строки меньше исходной длины\n";
        break;

    case 2:
        cout << "Количество слов меньше двух\n";
        break;

    default:
        cout << "Неизвестная ошибка\n";
        break;
    }


    return 0;
}
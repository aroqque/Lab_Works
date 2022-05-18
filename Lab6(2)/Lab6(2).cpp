#include "Header.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (;;)
    {
        char* s = new char[length];
        cout << "Введите строку: ";
        if (!cin.getline(s, length))
        {
            error_length();
            cout << "Строка с которой вы работаете: " << s << endl;
        }

        cout << "Исходная длина = " << getLength(s) << endl;

        int lastUpdated = 0;

        while (getLength(s) < length)
        {
            double_spaces(s, length);
        }

        cout << "Преобразованая строка: ";

        for (int i = 0; i < getLength(s); i++)
            cout << *(s + i);

        cout << endl;

        cout << "Итоговая длина = " << getLength(s) << endl;

        cout << endl;

        delete[] s;
    }
    return 0;
}
#include "Header.h"

int getLength(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void error_length()
{
    cout << "Вы превысили длину, строка была обрезана. " << endl;
    cin.clear();
    cin.ignore(256, '\n');
}

void add_space(char* str, size_t index, size_t n) {
    if (n > length) {
        cout << "Невозможно расширить массив." << endl;
    }
    for (auto i = n; i >= index; --i)
        str[i] = str[i - 1];
    str[index] = ' ';
}

char* double_spaces(char* str, size_t n) {
    for (int i = 0; i < n; i++)
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            if (getLength(str) >= length)
               break;

            else add_space(str, i++, n);
        }
    return str;
}
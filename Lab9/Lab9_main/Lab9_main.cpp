// Lab9_main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "windows.h"
#include <iostream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i, j, l, c;
    double a[100][100];
    srand(time(NULL));
    //заполнение массива случайными числами
    cout << "Введите количество рядов от 0 до 100: l="; cin >> l;
    cout << "Введите количество столбцов от 0 до 100: c="; cin >> c;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {

            a[i][j] = rand() % 9 + 1;
        }
    }
    //вывод массива на экран 
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    //вывод обновлённого массива на экран
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            cout << a[l - 1 - i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

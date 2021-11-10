﻿// Lab5_main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x, y;
    while (1)
    {
        printf("Введите значение x > "); /*ввод координат*/
        scanf("%lf", &x);

        printf("Введите значение y > ");
        scanf("%lf", &y);

        printf("\nx=%6.3lf; y=%6.3lf\n", x, y);/*Вывод только что введенных значений*/
        /*проверка условий*/
        if (((x * x + y * y) <= 1 && y <= 0 && x <= 0) || (x >= -1 && x <= 1 && y >= 0 && y <= 1) || ((x * x + y * y) <= 1 && y <= 0 && x >= 0) || (x <= 0 && x >= -1 && y >= 0 && y <= 1))
            printf("Точка попадает в область\n\n\n\n");
        else
            printf("Точка не попадает в область\n\n\n\n");
    }
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
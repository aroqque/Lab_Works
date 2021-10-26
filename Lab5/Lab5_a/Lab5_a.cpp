﻿// Lab5_a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "windows.h"
using namespace std;

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;
    double D;
    double x1, x2, x;
    while (1)
    {
        printf("Введите значение a > ");
        scanf("%lf", &a);
        printf("Введите значение b > ");
        scanf("%lf", &b);
        printf("Введите значение c > ");
        scanf("%lf", &c);
        D = (b * b - 4 * a * c);
        if (D > 0)
        {
            x1 = (-b - sqrt(D)) / (2 * a);
            x2 = (-b + sqrt(D)) / (2 * a);
            printf("\nУравнение имеет два корня: \n");
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n\n", x2);

        }
        else
        {
            if (D == 0)
            {
                x = (-b) / (2 * a);
                printf("\nУравнение имеет единственный корень: \n");
                printf("x = %lf\n\n", x);
            }
            else printf("\nУравнение не имеет корней\n\n");
        }
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

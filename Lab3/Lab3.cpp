﻿// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/**************************************************/
/*            Лабораторная работа №3              */
/*       Арифметические выражения и функции       */
/*                  Вариант №12.                  */
/**************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/* параметры, которые вводятся */
	double x, y;
	/* параметры, которые задаются в программе */
	double a = 10, b = 5;
	double t1, t2;   /* результаты */
	double ax; /* рабочая переменная */
	while (1) {
		printf("\n");
		printf("Ведите значение x>0 >\t");
		scanf("%lf", &x);
		printf("Введите значение y>0 >\t");
		scanf("%lf", &y);

		ax = a * x;
		if ((x > 0) & (y > 0))
		{
			t1 = 1 / pow(b, 3) * (pow(a, 2) * log(y / x) + (2 * ax) / y + (pow(y, 2) / 2 * (pow(x, 2))));
			printf("t1=%lg\n", t1);

			ax = (ax * 3.14) / 180;

			t2 = 1 / (2 * sqrt(2) * a) + (3 * (pow(sin(ax), 2)) - 1) / (pow(sin(ax), 2) - 1);
			/* t2 = 1 / (2 * sqrt(2) * a) + (3 * pow(sin(ax-1), 2)) / (pow(sin(ax-1), 2)); */
			printf("t2=%lg\n", t2);
		}
		else {
			printf("\nОшибка\n");
			printf("Введите значение x и y в обозначенных пределах\n");
		}
		/* return 0; */
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

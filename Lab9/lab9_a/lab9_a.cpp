// lab9_a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib >
using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(0));
	const int N = 100, M = 100;
	int Matrix[N][M];
	int string, col;
	int w = 4;
	int answer;
	while (true)
	{
		cout << "В чем состоит задача?" << endl;
		cout << "Чтобы задать матрицу и максимальный елемент переставить в начало введите (1):  " << endl;
		cout << "Чтобы задать матрицу и минимальный елемент переставить в конец введите (2): " << endl;
		cout << "Чтобы выйти из программы введите (0)" << endl;
		cin >> answer;

		if (answer == 1)
		{
			cout << "Введите количество строк (1-100): ";
			cin >> string;
			if (string > 100 || string < 1)

			{
				cout << endl;
				cout << "Введите значение количество строк в диапозоне (1-100): ";
				return 0;
			}

			cout << "Введите количество столбцов (1-100): ";
			cin >> col;
			if (col > 100 || col < 1)

			{
				cout << endl;
				cout << "Введите значение количества столбцов в диапозоне (1-100): ";
				return 0;
			}

			for (int i = 0; i < string; i++)
			{

				if (i % string)
					cout << endl;
				for (int j = 0; j < col; j++)
				{
					Matrix[i][j] = rand() % 100;
					cout << setw(w) << Matrix[i][j];
				}
			}
			int max_string;
			for (int i = 0; i < col; i++)
			{
				max_string = 0;

				for (int j = 1; j < string; j++)
				{
					if (Matrix[i][j] > Matrix[i][max_string])
					{
						max_string = j;
					}
				}
				swap(Matrix[i][0], Matrix[i][max_string]);
			}
			cout << endl;
			cout << "Перераспределенная матрица: " << endl;
			for (int i = 0; i < string; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					cout << setw(w) << Matrix[i][j];
				}
				cout << setw(w) << Matrix[i][col - 1] << endl;;
			}
			cout << endl;
		}

		if (answer == 2)
		{
			cout << "Введите количество строк (1-100): ";
			cin >> string;
			if (string > 100 || string < 1)

			{
				cout << endl;
				cout << "Введите значение количества строк в диапозоне (1-100): ";
				return 0;
			}

			cout << "Введите количество столбцов (1-100): ";
			cin >> col;
			if (col > 100 || col < 1)

			{
				cout << endl;
				cout << "Введите значение количества столбцов в диапозоне (1-100): ";
				return 0;
			}

			for (int i = 0; i < string; i++)
			{

				if (i % string)
					cout << endl;
				for (int j = 0; j < col; j++)
				{
					Matrix[i][j] = rand() % 100;
					cout << setw(w) << Matrix[i][j];
				}
			}
			int min_col;
		
			for (int j = 0; j < string; j++)
			{

				min_col = 0;
				for (int i = 1; i < col; i++)
				{


					if (Matrix[i][j] < Matrix[min_col][j])
					{
						min_col = i;
					}
				}

				swap(Matrix[string - 1][j], Matrix[min_col][j]);
			}
			cout << endl;
			cout << "Перераспределенная матрица: " << endl;
			for (int i = 0; i < string; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					cout << setw(w) << Matrix[i][j];
				}
				cout << setw(w) << Matrix[i][col - 1] << endl;;
			}
			cout << endl;
		}

		if (answer == 0)
		{
			cout << endl;
			cout << "Выход из программы, нажмите любую клавишу..." << endl;
			cout << endl << endl;
			return 0;
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

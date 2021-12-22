// lab10_b.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
using namespace std;
void array_fill(int arr[100][100], int row, int col)
{
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (rand() % 2)
			{
				arr[i][j] = rand() % 100;
			}
			else
			{
				arr[i][j] = rand() % 100 * (-1);
			}
		}
	}
}
void array_print(int arr[100][100], int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
}
int array_sort(int arr[100][100], int col, int k)
{

	int pl = 0;
	for (size_t i = 0; i < col; i++)
	{
		if (arr[k][i] >= 0)
		{
			pl++;
		}
	}
	return pl;
}
int main()
{
	setlocale(0, "rus");
	int row, col, k;
	const int N = 100, M = 100;
	int arr[N][M];

	cout << "Введите количество строк матрицы:" << endl;
	cin >> row;
	cout << "Введите количество столбцов матрицы:" << endl;
	cin >> col;

	array_fill(arr, row, col);
	array_print(arr, row, col);
	cout << endl;
	int result;
	for (int i = 0; i < row; i++)
	{

		cout << "В  " << i + 1 << " строке " << array_sort(arr, col, i) << " положительных " << "элементов" << endl;
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

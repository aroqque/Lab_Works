#include "Header.h"

void fill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 16;
	}

	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << "\n\n\n";
}

void check(int* arr, int size, int* brr)
{
	int summ = 0;
	int chisla = arr[0];
	int kolvo = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 3 && arr[i] < 8)
		{

			chisla = arr[i];
			summ += chisla;
			kolvo++;
		}

	}
	cout << "Количество элементов от 3 до 8: " << kolvo << endl;
	cout << "Сумма элементов от 3 до 8: " << summ << endl;


	cout << "Массив из элементов от 3 до 8: ";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 3 && arr[i] < 8)
		{
			*(brr + i) = *(arr + i);
			cout << *(arr + i) << "      ";
		}

	}
}
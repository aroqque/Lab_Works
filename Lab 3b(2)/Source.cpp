#include "Header.h"

void print_menu()
{
	cout << endl << endl << endl;
	printf("Какой массив вывести?\n");
	cout << "1.Начальный случайный массив A" << endl;
	cout << "2.Отрицательный массив B" << endl;
	cout << "3.Положительный массив C" << endl;
	cout << "4.Массив из нулей D" << endl;
	cout << "5.Упорядоченный массив A: " << endl;
	cout << "6.Выход";
	cout << ">";
}

int get_variant() {
	int variant;
	cin >> variant;
	if (variant < 1 || variant > 7)
	{
		cout << "Ошибка, выберите действия под номерами от 1 до 7" << endl;
		return 0;
	}
	else
		return variant;
}

void fill(int* arr, int size) //Случайное заполнение исходного массива
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 21 - 10;
	}
}
void print(int* arr, int size) //Печать исходного массива
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "  ";
	}
	cout << endl;
}
void copy_arr(int* arr, int* copy_a_arr, int size) //Копия исходного массива
{
	for (int i = 0; i < size; i++)
	{
		*copy_a_arr = *arr;

		copy_a_arr++, arr++;
	}
}

int b_arr_size(int* arr, int size) //Коррекция размера массива B
{
	int fact_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) < 0)
			fact_size++;
	}
	return fact_size;
}
int c_arr_size(int* arr, int size) //Коррекция размера массива C
{
	int fact_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) > 0)
			fact_size++;
	}
	return fact_size;
}
int d_arr_size(int* arr, int size) //Коррекция размера массива D
{
	int fact_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == 0)
			fact_size++;
	}
	return fact_size;
}
void el_B(int* a_arr, int* b_arr, int size) // Сортировка массива из положительных элементов
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (*(a_arr + i) < 0)

			*(b_arr + j) = *(a_arr + i), j++;
	}
}
void el_C(int* a_arr, int* c_arr, int size)  // Сортировка массива из положительных элементов
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (*(a_arr + i) > 0)

			*(c_arr + j) = *(a_arr + i), j++;
	}
}
void el_D(int* a_arr, int* d_arr, int size) // Сортировка массива из нулей
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (*(a_arr + i) == 0)

			*(d_arr + j) = *(a_arr + i), j++;
	}
}
void edited_a_arr(int* a_arr, int* arr, int size, int* start_position) // Редактирование массива А
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(a_arr + i + *start_position) = *(arr + i);
	}
	*start_position += i;
}
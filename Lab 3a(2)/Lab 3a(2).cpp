#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	int size;
	int variant;
	cout << "Введите размер массива" << endl;
	cin >> size;

	int* arr = new int[size];

	int* null_ptr = arr;


	int sum, c = 0;

	fill(arr, size);
	do
	{
		print_menu();

		variant = get_variant();
		switch (variant)
		{

		case 1:
		{
			system("cls");
			arr = null_ptr;
			cout << endl << "Относительный адрес: " << endl;
			print(arr, size);
			sum = 0, c = 0;
			for (int i = 0; i < size; i++)
			{
				if (*(arr + i) < 0)
					sum += *(arr + i), c++;
			}
			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");
		}break;

		case 2:
		{
			system("cls");
			arr = null_ptr;
			print(arr, size);
			cout << endl << "Абсолютный адрес:" << endl;
			sum = 0, c = 0;

			for (int i = 0; i < size; i++)
			{
				if (*arr < 0)
					sum += *arr, c++;
				arr++;
			}

			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");
		}break;

		case 3:
		{
			system("cls");
			arr = null_ptr;
			print(arr, size);
			cout << endl << "Без использования адресации: " << endl;
			sum = 0, c = 0;

			for (arr = null_ptr; arr < null_ptr + size; arr++)
			{
				if (*arr < 0)
					sum += *arr, c++;
			}

			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");
		}break;

		case 4:
		{
			system("cls");
			arr = null_ptr;
			print(arr, size);
			cout << endl << "Через массив указателей: " << endl;
			sum = 0, c = 0;

			int* ptr_arr[100];

			for (int i = 0; i < size; i++)
			{
				ptr_arr[i] = &arr[i];
			}

			for (int i = 0; i < size; i++)
			{
				if (*ptr_arr[i] < 0)
					sum += (*ptr_arr[i]), c++;
			}

			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");
		}break;

		case 5:
		{
			system("cls");
			arr = null_ptr;
			print(arr, size);
			cout << endl << "Указатель на указатель:" << endl;
			sum = 0, c = 0;
			int** ptr_ptr;

			for (int i = 0; i < size; i++)
			{
				ptr_ptr = &arr;
				if (**ptr_ptr < 0)
					sum += **ptr_ptr, c++;
				arr++;
			}

			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");

		}break;

		case 6:
		{
			system("cls");
			arr = null_ptr;
			print(arr, size);
			cout << endl << "В виде функции с параметрами указателями:" << endl;
			sum = 0, c = 0;

			foo(arr, size, &sum, &c);

			cout << endl << "Сумма отрицательных элементов: " << sum << endl;
			cout << "Кол-во отрицательных элементов: " << c << endl;
			system("pause");
			system("cls");
		}break;

		if (variant != 7)
			system("pause");
		}

	} while (variant != 7);

	delete[] arr;
}

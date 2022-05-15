#include "foo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int SIZE;
	cout << "Введите размерность матрицы: ";
	cin >> SIZE;
	cout << "\n";
	int sum_gd = 0, sum_pd = 1, variant;
	int** matrix = nullptr;
	int* min_col_el = new int[SIZE];
	int* max_row_el = new int[SIZE];
	int* arr;

	alloc_matrix(matrix, SIZE);
	fill_matrix(matrix, SIZE);
	print_matrix(matrix, SIZE);

	arr = foo(matrix, SIZE, min_col_el, max_row_el, &sum_gd, &sum_pd);

	do
	{
		print_menu();
		variant = get_variant();

		switch (variant)
		{
		case 1:
		{
			system("cls");
			print_matrix(matrix, SIZE);
		}break;

		case 2:
		{
			system("cls");
			print_matrix(matrix, SIZE);
			cout << "\n";
			print_array(min_col_el, SIZE);

		}break;

		case 3:
		{
			system("cls");
			print_matrix(matrix, SIZE);
			cout << "\n";
			print_array(max_row_el, SIZE);
		}break;

		case 4:
		{
			system("cls");
			print_matrix(matrix, SIZE);
			cout << "\n";
			cout << "Сумма по главной диагонали:\t" << *arr;
		}break;

		case 5:
		{
			system("cls");
			print_matrix(matrix, SIZE);
			cout << "\n";
			cout << "Произведение по побочной диагонали:\t" << *(arr + 1);
		}break;

		if (variant != 6)
			system("pause");
		else
			cout << "Ошибка!";
		}
	} while (variant != 6);

	release_matrix(matrix, SIZE);
	delete[]arr;
}
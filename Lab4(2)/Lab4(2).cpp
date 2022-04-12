#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int size;
	bool answer = true;
	do {

		cout << "Введите размер массива в диапозоне 1-100 " << endl;
		cin >> size;
		if (size < 1 || size > 100) cout << "Введите размер в диапозоне 1-100";
		system("cls");

		int* arr = new int[size];

		cout << "Начальный массив:" << endl;
		fill(arr, size);

		int kolvo = 0;
		int* brr = new int[kolvo];

		check(arr, size, brr);
		cout << "\n\n\n";

		cout << "Чтобы выполнять программу дальше, введите - 1" << endl << "Чтобы выйти из программы, введите - 0 " << endl;
		cin >> answer;
		system("pause");
		system("cls");

		delete[] arr;
		delete[] brr;
	} while (answer != false);

	return 0;
}
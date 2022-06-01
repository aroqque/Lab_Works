#include "foo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int x = 0;
	char fname[] = "text.bin";

	input(fname);
	cout << "Вывод первого файла:\n";
	read(fname);
	x = sum(fname);
	cout << "\n\n\n";
	cout << "Сумма = " << x;
	cout << "\n\n\n";
	sort(fname);
	cout << "\n";
	cout << "Вывод второго файла с замененным минимальным значением:\n";
	read(fname);
	cout << "\n\n\n";
	system("pause");

}
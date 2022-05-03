#include "foo.h"

void input(char* fname)
{
	FILE* f;
	fopen_s(&f, fname, "w+b");
	int a = 0;
	for (int i = 0; i < 20; i++) {
		a = rand() % 10 - 2;
		fwrite(&a, sizeof(int), 1, f);
	}
	fclose(f);
}

void read(char* fname) // считывание и вывод bin файла
{
	FILE* f;
	fopen_s(&f, fname, "r+b");

	int a;

	for (int i = 0; i < 20; i++)
	{
		fread(&a, sizeof(int), 1, f);
		cout << a << "    ";
	}
	fclose(f);

}

int sum(char* fname) //подсчет суммы заданных элементов
{
	FILE* f;
	int a, sum = 0;

	fopen_s(&f, fname, "r+b");

	fseek(f, 1 * sizeof(int), SEEK_SET);
	fread(&a, sizeof(int), 1, f);
	sum += a;

	fseek(f, 4 * sizeof(int), SEEK_SET);
	fread(&a, sizeof(int), 1, f);
	sum += a;

	fseek(f, 8 * sizeof(int), SEEK_SET);
	fread(&a, sizeof(int), 1, f);
	sum += a;

	fclose(f);
	return sum;
}

void sort(char* fname) // Сортировка и поиск минимального элемента
{
	FILE* f;
	int min = INT_MAX, index = 0;
	int x;
	fopen_s(&f, fname, "r+b");

	for (int i = 0; i < 20; i++) {
		fread(&x, sizeof(int), 1, f);
		if (x < min) min = x, index = i;
	}

	cout << "min = " << min;

	fseek(f, 0, SEEK_SET);

	while (!feof(f)) {
		fread(&x, sizeof(int), 1, f);
		if (x == min) {
			fseek(f, index * sizeof(int), SEEK_SET);
			x = 999;
			fwrite(&x, sizeof(int), 1, f);
			fseek(f, 0, SEEK_END);
		}
	}
	fclose(f);
}
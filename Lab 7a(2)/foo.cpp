#define _CRT_SECURE_NO_WARNINGS
#include "foo.h"

void fill_array(int* mas, const int N) {
	for (int i = 0; i < N; i++)
		*(mas + i) = rand() % 10;
}

void print_array(int* mas, const int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", *(mas + i));
}

void foo1(char* fname1, int* mas1, const int N) //заполняем массив
{

	FILE* f1;
	fopen_s(&f1, fname1, "r+t");

	if (!feof(f1))
		for (int i = 0; i < N; i++)
			fprintf(f1, "%d  ", *(mas1 + i));

	fclose(f1);
}

void foo2(char* fname1, char* fname2, int* mas1, int* mas2, const int N) //переписываем во второй текстовик и во второй массив
{

	FILE* f1;
	FILE* f2;
	fopen_s(&f1, fname1, "r+t");
	fopen_s(&f2, fname2, "r+t");

	for (int i = 0; i < N; i++)
		fscanf(f1, "%d", &*(mas2 + i));
	for (int i = 0; i < N; i++)
		fprintf(f2, "%d  ", *(mas2 + i));

	fclose(f1);
	fclose(f2);
}

void foo3(char* fname2, int x, const int N) //по-очередно вытаскивыем иксы
{
	FILE* f2;
	fopen_s(&f2, fname2, "r+t");

	for (int i = 0; i < N; i++) {
		fscanf(f2, "%d", &x);
		cout << i + 1 << ") x = " << x << "\n";
	}
	fclose(f2);
}
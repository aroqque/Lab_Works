#define _CRT_SECURE_NO_WARNINGS
#include "foo.h"

void fill_array(int* arr, const int N) 
{
	for (int i = 0; i < N; i++)
		*(arr + i) = rand() % 10;
}

void print_array(int* arr, const int N) 
{
	for (int i = 0; i < N; i++)
		printf("%d ", *(arr + i));
}
void foo(char* fname, int* mas, const int N)
{
	FILE* f1;
	fopen_s(&f1, fname, "w+b");
	fwrite(mas, sizeof(int), N, f1);
	fclose(f1);
}
void sum_foo(char* fname, int* arr, int* sum, const int N)
{
	FILE* f2;


	fopen_s(&f2, fname, "r+b");
	for (int i = 0; i < N; i++)
	{
		fread(&*(arr + i), sizeof(int), 1, f2);

		if (*(arr + i) % 2 == 0)
			*sum += *(arr + i);
	}
	fclose(f2);
}
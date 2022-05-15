#include "foo.h"

void alloc_matrix(int**& m, int s)
{
	m = new int* [s];
	for (int i = 0; i < s; i++)
	{
		*(m + i) = new int[s];
	}
}

void fill_matrix(int**& m, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			*(*(m + i) + j) = rand() % 30 - 10; // �� -10 �� 20
		}
	}
}

void print_matrix(int** m, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << *(*(m + i) + j) << "\t";
		}
		cout << "\n";
	}
}

int first_foo(int**& m, int s)
{
	int sum = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (*(*(m + i) + j) > 0)
				sum += *(*(m + i) + j);
		}
	}
	return sum;
}

int second_foo(int**& m, int s)
{
	int mult = 1;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (*(*(m + i) + j) < 0)
				mult *= *(*(m + i) + j);
		}
	}
	return mult;
}

void release_matrix(int**& m, int s)
{
	for (int i = 0; i < s; i++)
		delete[] * (m + i);

	delete[] m;
}

void print_menu()
{
	cout << "1. ������� �������\n";
	cout << "2. ������� ����� ������������� ���������\n";
	cout << "3. ������� ������������ ������������� ���������\n";
	cout << "4. �����";
	cout << "> ";

}
int get_variant()
{
	int variant;
	cin >> variant;
	if (variant < 1 || variant > 4)
	{
		cout << "������� ����� � ��������� �� 1 �� 4" << endl;
		return 0;
	}
	else
		return variant;
}

#include "foo.h"

void print_menu()
{
	cout << "\n";
	cout << "1. Use buble sorting\n";
	cout << "2. Use shake sorting\n";
	cout << "3. Exit\n";
	cout << "> ";
}

int get_variant()
{
	int variant;
	cin >> variant;
	if (variant < 1 || variant > 3)
	{
		cout << "Enter number 1 - 3" << endl;
		return 0;
	}
	else
		return variant;
}

void fill_array(int* a, int s)
{
	for (int i = 0; i < s; i++)
	{
		*(a + i) = rand() % 20;
	}
}

void print_array(int* a, int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << *(a + i) << "\t";
	}


}
void buble_sort(int* a, int s)
{

	for (int i = 0; i < s - 1; i++) {
		for (int j = 0; j < s - i - 1; j++) {
			if (*(a + j) > *(a + j + 1))
				swap(*(a + j), *(a + j + 1));
		}
	}
}

void shake_sort(int* a, int s)
{
	int leftMark = 1;
	int rightMark = s - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (*(a + i - 1) > *(a + i)) swap(*(a + i), *(a + i - 1));
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (*(a + i - 1) > *(a + i)) swap(*(a + i), *(a + i - 1));
		rightMark--;
	}
}

void choose(int* a, int s, void(*choose_sort)(int*, int))
{
	choose_sort(a, s);
}
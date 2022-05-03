#include "foo.h"
#define N 10

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	char fname1[] = "text1.txt";

	int arr1[N];
	int arr2[N];
	int x = 0;

	fill_array(arr1, N);
	cout << "Первый массив:\n";
	print_array(arr1, N);
	foo(fname1, arr1, N);
	sum_foo(fname1, arr2, &x, N);

	cout << "\n\nВторой массив:\n";
	print_array(arr2, N);

	cout << "\n\nСумма: " << x << endl;
	system("pause");
}

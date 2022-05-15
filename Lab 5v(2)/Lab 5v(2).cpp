#include "foo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int SIZE, variant;
	cout << "Enter size of array\n";
	cin >> SIZE;
	int* array = new int[SIZE];

	//void (*actions[])(int*, int) = { buble_sort, shake_sort };

	do
	{
		print_menu();
		variant = get_variant();

		switch (variant)
		{

		case 1:
		{
			system("cls");
			cout << "\n";
			fill_array(array, SIZE);
			print_array(array, SIZE);
			cout << "\n";
			choose(array, SIZE, buble_sort);
			//(*actions)(array,SIZE);
			print_array(array, SIZE);
			cout << "\n";
		}break;

		case 2:
		{
			system("cls");
			cout << "\n";
			fill_array(array, SIZE);
			print_array(array, SIZE);
			cout << "\n";
			choose(array, SIZE, shake_sort);
			//(*(actions + 1))(array, SIZE);
			print_array(array, SIZE);
			cout << "\n";
		}break;

		}
	} while (variant != 3);

	cout << "\n\n\n";
	delete[] array;
}
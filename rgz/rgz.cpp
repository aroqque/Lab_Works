// rgz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <chrono>
#define N 45 //Элементов в массиве
const int RUN = 32;

using namespace std;
void first_sorting(int arr[], int n); // Сортирова Шелли 
void second_sorting(int arr[], int n); // Сортировка Timsort
void ordered_array(int arr[], int n);  // Упорядоченный массив
void reverse_array(int arr[], int n);  // Развернутый массив
void disordered_array(int arr[], int n); // Неупорядоченный массив
void dur_array(double dur_arr[], int M); // Время

int main()
{
	int const M = 700; // Количество циклов
	setlocale(0, "rus");
	int arr[N];
	int reverse_arr[N];
	int disordered_arr[N];
	int disordered_arr_2[N];
	int temp;

	//Упорядоченый массив
	ordered_array(arr, N);

	//Вывод упорядоченого массива
	cout << "Упорядоченный массив :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Вызов первой функции
	first_sorting(arr, N);
	cout << endl << "Отсортированый уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Вызов второй функции
	second_sorting(arr, N);
	cout << endl << "Отсортированый уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}
	ordered_array(arr, N);
	cout << endl << endl << endl;

	//Обратный массив
	cout << "Обратный массив :";
	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	//Вызов первой функции
	first_sorting(reverse_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Возврат в обратный массив
	cout << endl << endl;
	cout << "Проверка заходимого массива :";
	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}
	cout << endl;

	//Вызов второй функции
	second_sorting(reverse_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}
	reverse_array(reverse_arr, N);
	cout << endl << endl << endl;
	cout << "Неупорядоченный массив :";
	disordered_array(disordered_arr, N);

	//Печать неупорядоченого массива
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}

	//Копия неупорядоченого массива
	for (int i = 0; i < N; i++)
	{
		disordered_arr_2[i] = disordered_arr[i];
	}

	//Вызов первой функции
	first_sorting(disordered_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}

	//Печать для наглядности, что во вторую сортировку входит неупорядоченый массив
	cout << endl << endl;
	cout << "Проверка заходимого массива :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr_2[i];
	}
	cout << endl;

	//Вызов второй функции
	second_sorting(disordered_arr_2, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr_2[i];
	}
	cout << endl;
	disordered_array(disordered_arr, N);

	//Подсчет времени
	double dur_arr[M];
	double aver_dur = 0;
	cout << endl;

	cout << "Упорядоченный массив" << endl; //1

	ordered_array(arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ordered_array(arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M);

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600)aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 1.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; // Обнуляем среднее значение
	ordered_array(arr, N); //Перезадаем массив

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ordered_array(arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 1.2 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение
	cout << endl << endl;


	cout << "Обратно упорядоченный массив" << endl;   //2

	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		reverse_array(reverse_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(reverse_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 2.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение

	reverse_array(reverse_arr, N); //Перезадаем массив
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		reverse_array(reverse_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(reverse_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 2.2 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение
	cout << endl << endl;


	cout << "Неупорядоченный массив" << endl; //3

	disordered_array(disordered_arr, N);

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}

	for (int i = 0; i < N; i++)  //Копия неупорядоченого массива
	{
		disordered_arr_2[i] = disordered_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		disordered_array(disordered_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(disordered_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 3.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение

	for (int i = 0; i < N; i++) //Копия массива с которым мы заходим в функцию
	{
		cout << setw(4) << disordered_arr_2[i];
	}

	for (int i = 0; i < M; i++)
	{
		disordered_array(disordered_arr_2, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(disordered_arr_2, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M);  //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 3.2 = %.8lf\n", aver_dur / 500);

	cout << endl << endl;
}
void ordered_array(int arr[], int n) //Функция задающая упорядоченый массив
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
}
void reverse_array(int arr[], int n) //Функция задающая обратно упорядоченый массив

{
	int i;
	int k = n;
	for (int i = 0; i < n; i++, --k)
	{
		arr[i] = k;
	}
}
void disordered_array(int arr[], int n) //Функция задающая неупорядоченый массив
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < n; i++)
	{
		swap(arr[i], arr[rand() % n]);

	}
}
void first_sorting(int arr[], int n) //Сортировка Шелла
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}
			arr[j] = tmp;
		}
}
//Тимсорт сортировка
void insertionSort(int arr[], int left, int right) // сортировка вставками
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void merge(int arr[], int l, int m, int r) // сортировка слиянием
{
	int len1 = m - l + 1, len2 = r - m;
	int left[100], right[100];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}
void second_sorting(int arr[], int n) // Финальный тимсорт
{
	for (int i = 0; i < n; i += RUN)
		insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
	for (int size = RUN; size < n;
		size = 2 * size)
	{
		for (int left = 0; left < n;
			left += 2 * size)
		{
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1),
				(n - 1));
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}
void dur_array(double dur_arr[], int M) //Сортировка по убыванию подсчитаных значений времени
{
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			if (dur_arr[i] < dur_arr[j])
			{
				int temp = dur_arr[i];
				dur_arr[i] = dur_arr[j];
				dur_arr[j] = temp;
			}
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

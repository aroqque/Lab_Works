#include "Header.h"

//#define ARRAY

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int size;

    //#ifdef ARRAY
    cout << "Введите размерность массива > ";
    cin >> size;
    if (size <= 0 || size > 10)
    {
        cout << "Введите значение от 1 до 10";
    }

    int* arr = new int[size * size];

    fill_array(arr, size);
    cout << "Изначальный одномерный массив:\n";
    print_array(arr, size);
    sort_array(arr, size);
}
#include "Header.h"
#define ARRAY

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    #ifdef ARRAY

    int size;
    cout << "Введите размерность массива > ";
    cin >> size;
    if (size <= 0 || size > 10)
    {
        cout << "Введите значение от 1 до 10";
    }
    else 
    {
        int* arr = new int[size * size];

        fill_array(arr, size);
        cout << "Изначальный массив:\n";
        print_array(arr, size);
        sort(arr, size);
        delete[]arr, arr = nullptr;
    }
    #else
    
    int size2;


    cout << "Введите количество  > ";
    cin >> size2;

    int** matrix = nullptr;

    alloc_matrix(matrix, size2);

    fill_matrix(matrix, size2);
    cout << "Изначальная матрица\n";
    print_matrix(matrix, size2);
    sort2(matrix, size2);


    #endif
}
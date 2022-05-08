#include "Header.h"


void fill_array(int* arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(arr + i * size + j) = rand() % 10;
        }
    }
}

void print_array(int* arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "  " << *(arr + i * size + j);
        }
        cout << endl;
    }
}
void sort(int* arr, int size)
{
    cout << "\n";
    cout << "Массив по задaнию:\n";

    for (int i = 0; i < size; i++)
    {
      
        int k = (i < size / 2) ? i : size - i - 1;
        for (int j = 0; j < size; j++)
        {
            cout << "  " << *(arr + k * size + j);
        }
        cout << endl;
    }
}


void alloc_matrix(int**& m, int size)
{
    m = new int* [size];
    for (int i = 0; i < size; i++)
    {
        *(m + i) = new int[size];
    }
}


void fill_matrix(int** m, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(*(m + i) + j) = rand() % 10;
        }
    }
}


void print_matrix(int** m, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "  " << *(*(m + i) + j);
        }
        cout << endl;
    }
}

void sort2(int** m, int size)
{
    cout << "\n";
    cout << "Массив по задaнию:\n";

    for (int i = 0; i < size; i++)
    {

        int k = (i < size / 2) ? i : size - i - 1;
        for (int j = 0; j < size; j++)
        {
            cout << "  " << *(*(m + k) + j);
        }
        cout << endl;
    }
}
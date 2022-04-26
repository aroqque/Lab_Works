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
            cout << "     " << *(arr + i * size + j);
        }
        cout << endl;
    }
}

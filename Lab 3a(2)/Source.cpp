#include "Header.h"

void fill(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 41 - 21;
    }
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void print_menu()
{
    //system("cls");
    printf("��� ������?\n");
    printf("1. ������������� �����\n");
    printf("2. ����� ���������� �����\n");
    printf("3. �� ������������ ���������\n");
    printf("4. ����� ������ ����������\n");
    printf("5. ����� ��������� �� ���������\n");
    printf("6. �������� � ���� ������� � ����������� �����������\n");
    printf("7. �����\n");
    printf(">");
}

int get_variant() {
    int variant;
    cin >> variant;
    if (variant < 1 || variant > 7)
    {
        cout << "������� ����� � ��������� 1 - 7" << endl;
        return 0;
    }
    else
        return variant;
}
void foo(int* arr, int size, int* sum, int* count) {
    for (int i = 0; i < size; i++)
    {
        if (*arr < 0) {
            *sum += *arr;
            (*count)++;
        }
        arr++;
    }
}
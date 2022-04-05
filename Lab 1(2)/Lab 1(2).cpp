// Lab 1(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct table
{
    char name[12];
    char sc[12];
    char cnt[12];
    char sq[12];
}
arr[10];

void input(int N, table arr[])
{
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ") " << "Введите: вид транспорта, № маршрута, протяженность маршрута (км), время в дороге (мин) >" << endl;
        cin >> arr[i].name >> arr[i].sc >> arr[i].cnt >> arr[i].sq;
    }
}
void random(int N, table arr[])
{
    srand(time(0));
    string symbol[3] = { "12","17","12a"}; 
    string names[3] = { "Тр", "Т-с","А"};
    string sign[3] = { "27.55","13.6","57.3"};
    string kilom[3] = { "75","57","117" };
    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr[i].name, names[rand() % 3].c_str());
        strcpy_s(arr[i].cnt, sign[rand() % 3].c_str());
        strcpy_s(arr[i].sc, symbol[rand() % 3].c_str());
        strcpy_s(arr[i].sq, kilom[rand() % 3].c_str());
    }
}

void print(int N, table arr[])
{
    cout << ("----------------------------------------------------------\n");
    cout << ("|           Ведомость общественного транспорта           |\n");
    cout << ("|--------------------------------------------------------|\n");
    cout << ("|    Вид     | № Маршрута | Протяженность |    Время в   |\n");
    cout << ("| транспорта |            |  маршрута(км) | дороге (мин) |\n");
    cout << ("|------------|------------|---------------|--------------|\n");

    for (int i = 0; i < N; i++)
    {
        printf("| %-10s | %-10s | %-13s | %-12s |\n", arr[i].name, arr[i].sc, arr[i].cnt, arr[i].sq);
    }
    cout << ("|--------------------------------------------------------|\n");
    cout << ("|     Примечание: Тр - трамвай,                          |\n");
    cout << ("|                 Т-с - троллейбус,                      |\n");
    cout << ("|                 А - автобус                            |\n");
    cout << ("----------------------------------------------------------\n");
}

void sort(int N, table arr[])
{
    struct table x;
    for (int i = 0; i < N - 1; i++)
    {
    int m = i; /* минимальный элемент - первый */
    for ( int j = i + 1; j < N; j++)  /* если текущий элемент > минимального, он становится минимальным */
        if (strcmp(arr[m].name, arr[j].name) > 0) m = j;
    if (m > i)
    {
        x = arr[i]; /* перестановка первого и минимального элементов */
        arr[i] = arr[m];
        arr[m] = x;
    }
    }
}

void print_menu()
{
    system("cls");
    printf("Какое действие выполнить?\n");
    printf("1. Заполнить структуру вручную\n");
    printf("2. Заполнить структуру случайно\n");
    printf("3. Отсортировать структуру\n");
    printf("4. Расспечатать структуру\n");
    printf("5. Выход\n");
    printf(">");
}

int get_variant() {
    int variant;
    cin >> variant;
    if (variant < 1 || variant > 5)
    {
        cout << "Ошибка, введите числа в диапозоне 1-5" << endl;
        return 0;
    }
    else
        return variant;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    bool answer;
    int N;
    int variant;
    do
    {
        print_menu();
        variant = get_variant();
        switch (variant)
        {
        case 1:
        {
            cout << "Сколько строк заполнять? --> ";
            cin >> N;
            input(N, arr);
        }break;

        case 2:
        {
            cout << "Сколько строк заполнять? --> ";
            cin >> N;
            random(N, arr);
        }break;

        case 3:
        {
            sort(N, arr);
        }break;

        case 4:
        {
            print(N, arr);
        }break;
        }
        if (variant != 5)
        {
            system("pause");
        }
    } while (variant != 5);

    return 0;
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

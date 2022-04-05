
#pragma once
#include "Header.h"

void input(int N, table arr[])
{
 #ifdef PRINT_TYPE()
    cout << "PRINT_TYPE обнаружен!" << endl;
    cout << "Заполните таблицу вручную." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ") " << "Введите: вид транспорта, № маршрута, протяженность маршрута (км), время в дороге (мин) >" << endl;
        cin >> arr[i].name >> arr[i].sc >> arr[i].cnt >> arr[i].sq;
    }

 #else
    cout << "PRINT_TYPE не найден!" << endl;
    cout << "Таблица будет заполнена случайным образом." << endl;
    srand(time(0));
    string symbol[3] = { "12","17","12a" };
    string names[3] = { "Тр", "Т-с","А" };
    string sign[3] = { "27.55","13.6","57.3" };
    string kilom[3] = { "75","57","117" };
    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr[i].name, names[rand() % 3].c_str());
        strcpy_s(arr[i].cnt, sign[rand() % 3].c_str());
        strcpy_s(arr[i].sc, symbol[rand() % 3].c_str());
        strcpy_s(arr[i].sq, kilom[rand() % 3].c_str());
    }
 #endif
 #ifdef DEBUG

 cout << endl << endl;
 cout << "DEBUG defined!" << endl;
 cout << __FILE__ << endl;
 cout << __DATE__ << endl;
 cout << __FUNCTION__ << endl;
 cout << __TIME__ << endl;
 cout << endl << endl;
 #else
  cout << "DEBUG undefined!" << endl;
 #endif
}
/*void random(int N, table arr[])
{
    srand(time(0));
    string symbol[3] = { "12","17","12a" };
    string names[3] = { "Тр", "Т-с","А" };
    string sign[3] = { "27.55","13.6","57.3" };
    string kilom[3] = { "75","57","117" };
    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr[i].name, names[rand() % 3].c_str());
        strcpy_s(arr[i].cnt, sign[rand() % 3].c_str());
        strcpy_s(arr[i].sc, symbol[rand() % 3].c_str());
        strcpy_s(arr[i].sq, kilom[rand() % 3].c_str());
    }
}*/

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
        printf("| %-10s | %-10s | %-13s | %-12s | \n", arr[i].name, arr[i].sc, arr[i].cnt, arr[i].sq);
    }
    cout << ("|--------------------------------------------------------|\n");
    cout << ("|     Примечание: Тр - трамвай,                          |\n");
    cout << ("|                 Т-с - троллейбус,                      |\n");
    cout << ("|                 А - автобус                            |\n");
    cout << ("----------------------------------------------------------\n");

 #ifdef DEBUG

    cout << endl << endl;
    cout << "DEBUG defined!" << endl;
    cout << __FILE__ << endl;
    cout << __DATE__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __TIME__ << endl;
    cout << endl << endl;
 #else
    cout << "DEBUG undefined!" << endl;
 #endif
}

void sort(int N, table arr[])
{
    struct table x;
    for (int i = 0; i < N - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < N; j++)
            if (strcmp(arr[m].name, arr[j].name) > 0) m = j;
        if (m > i)
        {
            x = arr[i];
            arr[i] = arr[m];
            arr[m] = x;
        }
    }
 #ifdef DEBUG

    cout << endl << endl;
    cout << "DEBUG defined!" << endl;
    cout << __FILE__ << endl;
    cout << __DATE__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __TIME__ << endl;
    cout << endl << endl;
 #else
    cout << "DEBUG undefined!" << endl;
 #endif
}

void print_menu()
{
    system("cls");
    printf("Какое действие выполнить?\n");
    printf("1. Заполнить структуру\n");
    //printf("2. Заполнить структуру случайно\n");
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

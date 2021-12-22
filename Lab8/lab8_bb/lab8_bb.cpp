// lab8_bb.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr_size;
    cout << "Введите количество элементов в массиве" << endl;
    cin >> arr_size;

    int arr[100]{};
    int answer;

    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i + 1;

        cout << arr[i] << setw(3);
    }

    cout << endl << endl;

    while (true) {

        cout << "\nЧто вы хотите сделать с массивом?" << endl;
        cout << "Чтобы вставить элементы введите (1): " << endl;
        cout << "Чтобы удалить элементы введите (2): " << endl;
        cout << "Чтобы выйти из программы введите (0):" << endl;

        cin >> answer;

        if (answer == 0) {

            cout << "\nНажмите любую клавишу чтобы выйти...." << endl << endl;
            break;
        }

        int new_arr, new_el, new_size;
        int answer_add, amount_el_add;
        int el_add = 0;
        if (answer == 1) {

            cout << "Введите элемент который вы хотите добавить: " << endl;
            cin >> answer_add;

            cout << "Введите количество элементов которые вы хотите добавить: " << endl;
            cin >> amount_el_add;

            cout << "Введите номер элемента с которого мы начнем добавлять элементы в массив: " << endl;
            cin >> el_add;

            int new_arr[100];
            amount_el_add = abs(amount_el_add);

            for (int i = 0; i < 100; i++)
            {
                new_arr[i] = arr[i];
            }
            arr_size += amount_el_add;

            el_add--;
            int end_el = el_add + amount_el_add; //элементы которые хотим добавить + их количество
            int j = 0;
            for (int i = 0; i < 100; i++)
            {
                if (i >= el_add && i < end_el)
                {
                    arr[i] = answer_add;
                }
                else
                {
                    arr[i] = new_arr[j];
                    j++;
                }
            }


            cout << endl << "Новый массив: " << endl;

            for (int new_i = 0; new_i < arr_size; new_i++)
            {
                cout << setw(3) << arr[new_i];

            }

            cout << endl << endl;
        }

        int amount_el, el, i;

        if (answer == 2) {

            cout << "\nВведите количество элементов, которые вы хотите удалить: \n";
            cin >> amount_el;
            amount_el = abs(amount_el);

            cout << "Введите номер элемента с которого мы начнем удаление (от 1 до 10): " << amount_el << " \n";
            cin >> el;
            el = abs(el);
            if (el > 10)
            {
                cout << "Ошибка, данного элемента не существует \n\n";
            }
            else
            {
                if (amount_el > 10 || amount_el == 0)
                {
                    cout << "Введите количество элементов, которое вы хотите (от 1 до 10): \n\n";
                }
                else
                {
                    el -= 1;
                    for (i = el; i < el + amount_el; i++)
                    {
                        arr[i] = 0;
                    }
                    for (i = 0; i < arr_size; i++)
                    {
                        if (arr[i] != 0)
                        {
                            cout << arr[i] << setw(3);
                        }
                    }
                    cout << "\n\n";
                }
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

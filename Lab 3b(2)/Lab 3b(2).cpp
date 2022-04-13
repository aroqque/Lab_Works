#include "Header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    const int size = 20;
    int variant;
    int start_position = 0;
    srand(time(0));

    int a_size = 0,
        b_size = 0,
        c_size = 0,
        d_size = 0;

    cout << "Введите размер массива(до 20) -> ";
    cin >> a_size;

    int a_arr[size];
    int copy_a_arr[size];
    int b_arr[size];
    int c_arr[size];
    int d_arr[size];

    if (a_size < 1 || a_size > size) cout << "Ошибка, размер массива не должен превышать 20 элементов. ", exit(0);
    cout << "Массив A: " << endl;

    fill(a_arr, a_size); //заполнение массива a_arr
    copy_arr(a_arr, copy_a_arr, a_size); //Делаем копию массива a_arr, сохраняем элементы для edited_a_arr
    print(a_arr, a_size);

    b_size = b_arr_size(a_arr, a_size); //переопределяем размер массива size b_arr
    el_B(a_arr, b_arr, a_size); //заполнение массива b_arr

    c_size = c_arr_size(a_arr, a_size); //переопределяем размер массива size c_arr
    el_C(a_arr, c_arr, a_size); //заполнение массива c_arr

    d_size = d_arr_size(a_arr, a_size); //переопределяем размер массива d_arr
    el_D(a_arr, d_arr, a_size); //заполнение массива d_arr

    edited_a_arr(a_arr, d_arr, d_size, &start_position); // первыми выводим нули
    edited_a_arr(a_arr, b_arr, b_size, &start_position); // вторыми выводим отрицательные элементы
    edited_a_arr(a_arr, c_arr, c_size, &start_position); // третьими выводим положительные элементы

    do {
        print_menu();

        variant = get_variant();


        switch (variant) {
        case 1:
            system("cls");

            cout << endl;
            cout << "Массив A: " << endl;
            print(copy_a_arr, a_size);
            break;


        case 2:
            system("cls");

            if (b_size == 0) cout << "Отрицательные числа отсутсвуют ";
            cout << endl;
            cout << "Массив B: " << endl;
            print(b_arr, b_size);
            break;
        case 3:
            system("cls");

            if (c_size == 0)
                cout << "Положительные числа отсутсвуют";

            cout << endl;
            cout << "Массив C: " << endl;
            print(c_arr, c_size);
            break;

        case 4:
            system("cls");

            if (d_size == 0)
            {
                cout << "Нули отсутсвуют";
            }

            else
            {
                cout << endl;
                cout << "Массив D: " << endl;
                print(d_arr, d_size);
            }
            break;

        case 5:
            system("cls");

            cout << "Отредактированый массив А:" << endl;
            print(a_arr, a_size);
            break;

        }


    } while (variant != 6);
    return 0;
}


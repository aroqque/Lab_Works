#include "foo.h"
#define _CRT_SECURE_NO_WARNINGS

void hand_input(FILE* f)
{
    int i; int N;
    table arr;
    cout << "������� ���������� �����, ������� ����� ���������: ";
    cin >> N;
    cout << "���������� ������: \n";
    fseek(f, 0, SEEK_END);
    for (i = 0; i < N; i++)
    {
        cin >> arr.name;
        if (strcmp(arr.name, "***") == 0) break;
        cin >> arr.sc >> arr.cnt >> arr.sq;
        fprintf(f, "\n%-10s   %-10s   %-13s   %-12s", arr.name, arr.sc, arr.cnt, arr.sq);
    }
}



void random_input(FILE* f)
{
    table arr;
    fseek(f, 0, SEEK_END);

    int N;
    cout << "������� ���������� �����, ������� ����� ���������: ";
    cin >> N;
    string symbol[3] = { "12","17","12a" };
    string names[3] = { "��", "�-�", "�" };
    string sign[3] = { "27.55","13.6","57.3" };
    string kilom[3] = { "75","57","117" };

    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr.name, names[rand() % 3].c_str());
        strcpy_s(arr.cnt, sign[rand() % 3].c_str());
        strcpy_s(arr.sc, symbol[rand() % 3].c_str());
        strcpy_s(arr.sq, kilom[rand() % 3].c_str());
        fprintf(f, "\n%-10s   %-10s   %-13s   %-12s", arr.name, arr.sc, arr.cnt, arr.sq);
    }

}


void random_end_input(FILE* f, char* fname)
{
    table arr;
    table arr_temp;

    FILE* temp;
    fopen_s(&temp, "temp.txt", "w+");


    int N;
    cout << "\n������� ���������� �����, ������� ����� ���������: ";
    cin >> N;
    string symbol[3] = { "12","17","12a" };
    string names[3] = { "��", "�-�", "�" };
    string sign[3] = { "27.55","13.6","57.3" };
    string kilom[3] = { "75","57","117" };

    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr.name, names[rand() % 3].c_str());
        strcpy_s(arr.cnt, sign[rand() % 3].c_str());
        strcpy_s(arr.sc, symbol[rand() % 3].c_str());
        strcpy_s(arr.sq, kilom[rand() % 3].c_str());
        fprintf(f, "\n%-10s   %-10s   %-13s   %-12s", arr.name, arr.sc, arr.cnt, arr.sq);
    }

    fseek(f, 0, SEEK_SET);
    while (!feof(f)) {
        if (f != NULL) {
            fscanf(f, "%s  %s  %s  %s", &arr_temp.name, &arr_temp.sc, &arr_temp.cnt, &arr_temp.sq);
            fprintf(temp, "\n%-10s   %-10s   %-13s   %-12s", arr_temp.name, arr_temp.sc, arr_temp.cnt, arr_temp.sq);
        }

    }
    fclose(f);
    fclose(temp);
    remove(fname);
    rename("temp.txt", fname);
}



void input_in_file(char* fname, int* mode)
{
    FILE* f;
    fopen_s(&f, fname, "r+t");


    if (*mode == 1)
        hand_input(f);
    if (*mode == 2)
        random_input(f);
    if (*mode == 3)
        random_end_input(f, fname);
    if (*mode == 4)
        random_input(f);


    if (!f == NULL)fclose(f);
}



void one_material_print(char* fname)
{
    table arr;
    FILE* f;

    fopen_s(&f, fname, "r+t");


    int N = 0;
    cout << "����� ������ �������?";
    cout << "\n������� ����� ������: ";
    cin >> N;
    if (N < 1) {
        system("cls"); cout << "������� ����� ������ 0\n"; fclose(f); return;
    }
    cout << ("----------------------------------------------------------\n");
    cout << ("|           ��������� ������������� ����������           |\n");
    cout << ("|--------------------------------------------------------|\n");
    cout << ("|    ���     | � �������� | ������������� |    ����� �   |\n");
    cout << ("| ���������� |            |  ��������(��) | ������ (���) |\n");
    cout << ("|------------|------------|---------------|--------------|\n");


    for (; N - 1 >= 0; ) {

        fscanf(f, "%s  %s  %s  %s", &arr.name, &arr.sc, &arr.cnt, &arr.sq);
        N--;
    }
    printf("| %-10s | %-10s | %-13s | %-12s |\n", arr.name, arr.sc, arr.cnt, arr.sq);


    cout << ("|--------------------------------------------------------|\n");
    cout << ("|     ����������: �� - �������,                          |\n");
    cout << ("|                 �-� - ����������,                      |\n");
    cout << ("|                 � - �������                            |\n");
    cout << ("----------------------------------------------------------\n");

    if (f != NULL)fclose(f);
}



void all_materials_print(char* fname)
{
    table arr;
    FILE* f;

    fopen_s(&f, fname, "r+t");

    cout << ("----------------------------------------------------------\n");
    cout << ("|           ��������� ������������� ����������           |\n");
    cout << ("|--------------------------------------------------------|\n");
    cout << ("|    ���     | � �������� | ������������� |    ����� �   |\n");
    cout << ("| ���������� |            |  ��������(��) | ������ (���) |\n");
    cout << ("|------------|------------|---------------|--------------|\n");


    while (!feof(f)) {
        fscanf(f, "%s  %s  %s  %s", &arr.name, &arr.sc, &arr.cnt, &arr.sq);
        printf("| %-10s | %-10s | %-13s | %-12s |\n", arr.name, arr.sc, arr.cnt, arr.sq);
    }


    cout << ("|--------------------------------------------------------|\n");
    cout << ("|     ����������: �� - �������,                          |\n");
    cout << ("|                 �-� - ����������,                      |\n");
    cout << ("|                 � - �������                            |\n");
    cout << ("----------------------------------------------------------\n");

    if (f != NULL)fclose(f);
}



void clear_file(char* fname) {
    FILE* f;
    fopen_s(&f, fname, "w");
    if (f != NULL)fclose(f);
}



void print_menu()
{
    system("cls");
    printf("����� �������� ���������?\n");
    printf("1. ���� ������� � ������ � ����\n");
    printf("2. ���� ��������� ������� � ������ � ����\n");
    printf("3. �������� ������ � ������ �����\n");
    printf("4. �������� ������ � ����� �����\n");
    printf("5. ������ ����� ������ �� �����\n");
    printf("6. ������ ���� ������� �� �����\n");
    printf("7. �������� ����\n");
    printf("8. �����\n");
    printf(">");
}



int get_variant() {
    int variant;
    cin >> variant;
    if (variant < 1 || variant > 8)
    {
        cout << "������, ������� ����� � ��������� 1-8" << endl;
        return 0;
    }
    else
        return variant;
}
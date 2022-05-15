#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

int get_variant();
void print_menu();
void fill_array(int* a, int s);
void print_array(int* a, int s);
void buble_sort(int* a, int s);
void shake_sort(int* a, int s);
void choose(int* a, int s, void(*choose_sort)(int*, int));
#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int get_variant();
void print_menu();
void fill(int* arr, int size);
void print(int* arr, int size);
void foo(int* arr, int size, int* sum, int* count);
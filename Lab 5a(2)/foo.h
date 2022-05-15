#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;
void print_menu();
int get_variant();
void fill_matrix(int**& m, int s);
void alloc_matrix(int**& m, int s);
void print_matrix(int** m, int s);
void print_array(int* a, int s);
void release_matrix(int**& m, int s);

int*& foo(int**& m, int s, int* min_col, int* max_row, int* sum_gd, int* sum_pd);
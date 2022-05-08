#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

void fill_array(int* a, int size);
void print_array(int* a, int size);
void sort(int* a, int s);
void alloc_matrix(int**& m, int size);
//void release_matrix(int**& m, int size);

void fill_matrix(int** m, int size);
void print_matrix(int** m, int size);
void sort2(int** m, int size);
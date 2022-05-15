#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;
void alloc_matrix(int**&, int);
void fill_matrix(int**& m, int s);
void print_matrix(int**, int s);
int first_foo(int**& m, int s);
int second_foo(int**& m, int s);
void release_matrix(int**& m, int s);
int get_variant();
void print_menu();
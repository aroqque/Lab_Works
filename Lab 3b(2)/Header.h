#pragma once
#include "windows.h"
#include <iostream>
#include <time.h>
using namespace std;


int get_variant();
void print_menu();

void fill(int*, int);
void print(int*, int);
void copy_arr(int*, int*, int);

int b_arr_size(int*, int);
int c_arr_size(int*, int);
int d_arr_size(int*, int);
void edited_a_arr(int*, int*, int, int*);

void el_B(int*, int*, int);
void el_C(int*, int*, int);
void el_D(int*, int*, int);
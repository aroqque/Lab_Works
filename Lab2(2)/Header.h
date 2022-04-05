#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>
#include <ctime>
#include "struct.h"

#define _CRT_SECURE_NO_WARNINGS
#define PRINT_TYPE
#define DEBUG
using namespace std;

void input(int N, table[]);
//void random(int N, table[]);
void print(int N, table[]);
void sort(int N, table[]);
void print_menu();
int get_variant();
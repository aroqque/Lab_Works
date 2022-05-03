#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>
#include <ctime>

using namespace std;

struct table
{
    char name[12];
    char sc[12];
    char cnt[12];
    char sq[12];
};
void input_in_file(char*, int*);
void one_material_print(char*);
void all_materials_print(char*);
void clear_file(char*);
void print_menu();
int get_variant();
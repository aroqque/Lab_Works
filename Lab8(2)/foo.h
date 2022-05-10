#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "Windows.h"
#include <iomanip>
using namespace std;

struct table
{
    char name[12];
    char type[12];
    char cnt[12];
    char sq[12];
    struct table* next;
};

table* create_list_by_hand();
table* create_list_random();
table* search_by_name(table* head, char* name);
table* search_by_type(table* head, char* type);
table* search_by_cnt(table* head, char* cnt);
table* search_by_sq(table* head, char* sq);
table* read_from_file();
void print_list(table* head);
void add_to_begin(table** head);
void add_to_end(table* head);
void add_after_element(table* head);
void delete_first(table** head);
void delete_last(table** head);
void delete_element(table** head);
void sort(table* head);
void input_in_file(table* head);
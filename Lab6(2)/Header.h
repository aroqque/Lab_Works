#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
using namespace std;
#define length 30
int getLength(char* str);
void error_length();
void add_space(char* str, size_t index, size_t n);
char* double_spaces(char* str, size_t n);
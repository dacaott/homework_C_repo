#ifndef DOUBLE_H
#define DOUBLE_H

#include <stddef.h>

// вывод числа в формате ±m*2^p
void printDouble(double number);

// получение строки с представлением (+-)m*2^p
void getDoubleString(double number, char* outBuffer, size_t bufferSize);

#endif
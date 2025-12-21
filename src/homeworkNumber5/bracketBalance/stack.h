#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* createStack(void);
void deleteStack(Stack* stack);

void initStack(Stack* stack);

void push(Stack* stack, int value);

// Удаление верхнего элемента и возвращение значения
int pop(Stack* stack, int* outValue);

// Просмотр верхнего элемента без удаления и возвращение значения
int peek(const Stack* stack, int* outValue);

bool isEmpty(const Stack* stack);
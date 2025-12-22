#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

// Создаёт стек и выделяет память
Stack* createStack(void);

// Очистка стека и освобождение памяти
void deleteStack(Stack* stack);

// Инициализация стека
void initStack(Stack* stack);

// Добавление элемента в стек
bool push(Stack* stack, int value);

// Удаление верхнего элемента и возвращение значения
bool pop(Stack* stack, int* outValue);

// Просмотр верхнего элемента без удаления
bool peek(const Stack* stack, int* outValue);

// Проверка, пуст ли стек
bool isEmpty(const Stack* stack);

// Очистка стека и освобождение памяти
void deleteStack(Stack* stack);
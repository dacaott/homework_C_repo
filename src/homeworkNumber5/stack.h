#pragma once
#include <stdbool.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
} Stack;

// Создаёт стек и выделяет память
Stack* createStack(void);

// Очистка стека и освобождение памяти
void deleteStack(Stack* stack);

// Инициализация стека
void initStack(Stack* stack);

// Добавление элемента в стек
void push(Stack* stack, int value);

// Удаление верхнего элемента и возвращение значения
int pop(Stack* stack, int* outValue);

// Просмотр верхнего элемента без удаления
int peek(const Stack* stack, int* outValue);

// Проверка, пуст ли стек
bool isEmpty(const Stack* stack);

// Очистка стека и освобождение памяти
void deleteStack(Stack* stack);
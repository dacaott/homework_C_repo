#include "stack.h"
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* head;
};

// Создание нового стека
Stack* createStack(void)
{
    Stack* stack = malloc(sizeof(struct Stack));
    if (stack)
        stack->head = NULL;
    return stack;
}

// Удаление стека
void deleteStack(Stack* stack)
{
    if (stack == NULL)
        return;
    while (stack->head) {
        StackNode* temp = stack->head;
        stack->head = temp->next;
        free(temp);
    }
    free(stack);
}

// Инициализация стека
void initStack(Stack* stack)
{
    if (stack == NULL)
        return;
    stack->head = NULL;
}

// Добавление элемента
void push(Stack* stack, int value)
{
    if (stack == NULL)
        return;

    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node)
        return;

    node->value = value;
    node->next = stack->head;
    stack->head = node;
}

// Удаление верхнего элемента
// и возвращение значения 0 если OK, 1 если стек пустой или не инициализирован
int pop(Stack* stack, int* outValue)
{
    if (stack == NULL || stack->head == NULL) {
        return 1;
    }

    *outValue = stack->head->value;
    StackNode* oldNode = stack->head;
    stack->head = oldNode->next;
    free(oldNode);
    return 0;
}

// Просмотр верхнего элемента
int peek(const Stack* stack, int* outValue)
{
    if (stack == NULL || stack->head == NULL)
        return 1;

    *outValue = stack->head->value;
    return 0;
}

// Проверка, пуст ли стек
bool isEmpty(const Stack* stack)
{
    return stack == NULL || stack->head == NULL;
}

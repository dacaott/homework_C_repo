#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* head;
};

Stack* createStack(void)
{
    Stack* stack = malloc(sizeof(Stack));
    if (stack)
        stack->head = NULL;
    return stack;
}

// Добавление элемента
bool push(Stack* stack, int value)
{
    if (stack == NULL)
        return false;

    StackNode* node = malloc(sizeof(StackNode));
    if (!node)
        return false;

    node->value = value;
    node->next = stack->head;
    stack->head = node;
    return true;
}

// Удаление верхнего элемента и возвращение значения
bool pop(Stack* stack, int* outValue)
{
    if (stack == NULL || stack->head == NULL) {
        return false;
    }

    StackNode* oldNode = stack->head;
    int res = oldNode->value;
    stack->head = oldNode->next;
    free(oldNode);
    return true;
}

// Просмотр верхнего элемента без удаления
bool peek(const Stack* stack, int* outValue)
{
    if (stack == NULL || stack->head == NULL) {
        return false;
    }
    *outValue = stack->head->value;
    return true;
}

// Проверка, пуст ли стек
bool isEmpty(const Stack* stack)
{
    return stack == NULL || stack->head == NULL;
}

// Очистка стека и освобождение памяти
void deleteStack(Stack* stack)
{
    if (stack == NULL)
        return;

    while (stack->head != NULL) {
        StackNode* temp = stack->head;
        stack->head = temp->next;
        free(temp);
    }
}
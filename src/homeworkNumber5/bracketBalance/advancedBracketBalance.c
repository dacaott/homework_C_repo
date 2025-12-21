#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isBalanced(const char* str)
{
    Stack* stack = createStack();
    if (stack == NULL)
        return false;

    for (int i = 0; str[i] != '\0'; i++) {
        char current = str[i];

        bool isOpen = (current == '(' || current == '[' || current == '{');

        if (isOpen) {
            push(stack, current);
        } else if (current == ')' || current == ']' || current == '}') {
            if (isEmpty(stack)) {
                deleteStack(stack);
                free(stack);
                return false;
            }

            int top;
            if (pop(stack, &top) != 0) {
                deleteStack(stack);
                free(stack);
                return false;
            }

            // Проверяем соответствие скобок
            if ((current == ')' && top != '(') || (current == ']' && top != '[') || (current == '}' && top != '{')) {
                deleteStack(stack);
                free(stack);
                return false;
            }
        }
    }

    // Если после обработки всей строки стек пуст - сбалансировано
    bool result = isEmpty(stack);
    deleteStack(stack);
    return result;
}

int main()
{
    char input[256];

    printf("Введите строку для проверки баланса скобок: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    // убираем символ новой строки, если он есть
    input[strcspn(input, "\n")] = '\0';

    if (isBalanced(input)) {
        printf("Скобки сбалансированы\n");
    } else {
        printf("Скобки НЕ сбалансированы\n");
    }

    return 0;
}
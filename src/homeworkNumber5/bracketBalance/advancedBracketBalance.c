#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isClosing(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool isOpen(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isBalanced(const char* str)
{
    Stack* stack = createStack();
    if (stack == NULL)
        return false;

    bool balanced = true;

    for (int i = 0; str[i] != '\0'; i++) {
        char current = str[i];

        if (isOpen(current)) {
            if (!push(stack, current)) {
                balanced = false;
                break;
            }
        } else if (isClosing(current)) {
            if (isEmpty(stack)) {
                balanced = false;
                break;
            }

            int top;
            if (!pop(stack, &top)) {
                balanced = false;
                break;
            }

            if (!isMatching((char)top, current)) {
                balanced = false;
                break;
            }
        }
    }

    if (balanced && !isEmpty(stack)) {
        balanced = false;
    }
    deleteStack(stack);
    return balanced;
}

int main()
{
    char input[256];

    printf("Введите строку (макс. 255 символов) для проверки баланса скобок: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    if (isBalanced(input)) {
        printf("Скобки сбалансированы\n");
    } else {
        printf("Скобки НЕ сбалансированы\n");
    }

    return 0;
}
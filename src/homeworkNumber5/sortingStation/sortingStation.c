#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция определения приоритета оператора
int getPriority(char operand)
{
    if (operand == '+' || operand == '-') {
        // низкий приоритет для + и -
        return 1;
    } else if (operand == '*' || operand == '/') {
        // высокий приоритет для * и /
        return 2;
    }
    // для других символов
    return 0;
}

// Функция преобразования инфиксного выражения в постфиксное
char* convertString(const char* string, int len)
{
    Stack stack;
    initStack(&stack);
    // каждый символ + пробел
    char* queue = malloc(len * 2 + 1);
    if (queue == NULL) {
        return NULL;
    }
    // текущий индекс в очереди
    int countForQueue = 0;
    int i = 0;

    while (i < len) {
        char ch = string[i];

        if (isspace(ch)) {
            // пропускаем пробельные символы
            ++i;
            continue;
        }

        if (isdigit(ch)) {
            // если цифра, добавляем её к результату
            queue[countForQueue++] = ch;
            queue[countForQueue++] = ' ';
        } else if (ch == '(') {
            // если открывающая скобка, помещаем в стек
            push(&stack, ch);
        } else if (ch == ')') {
            // если закрывающая скобка, вытягиваем из стека, пока не встретим '('
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                queue[countForQueue++] = (char)pop(&stack);
                queue[countForQueue++] = ' ';
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                // удаляем '(' из стека
                pop(&stack);
            } else {
                // не нашли '(' — ошибка
                deleteStack(&stack);
                free(queue);
                return NULL;
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // если оператор, вытягиваем из стека все операторы с приоритетом >= текущего
            while (!isEmpty(&stack) && getPriority((char)peek(&stack)) >= getPriority(ch) && peek(&stack) != '(') {
                queue[countForQueue++] = (char)pop(&stack);
                queue[countForQueue++] = ' ';
            }
            // помещаем текущий оператор в стек
            push(&stack, ch);
        } else {
            // неожидаемый символ
            deleteStack(&stack);
            free(queue);
            return NULL;
        }
        // переходим к следующему символу
        ++i;
    }

    // после обработки всей строки вытягиваем оставшиеся операторы из стека
    while (!isEmpty(&stack)) {
        char topChar = (char)peek(&stack);
        if (topChar == '(') {
            // осталась незакрытая скобка — ошибка
            deleteStack(&stack);
            free(queue);
            return NULL;
        }
        queue[countForQueue++] = (char)pop(&stack);
        queue[countForQueue++] = ' ';
    }

    deleteStack(&stack);

    if (countForQueue > 0) {
        // убрать последний пробел
        queue[countForQueue - 1] = '\0';
    } else {
        queue[countForQueue] = '\0';
    }

    return queue;
}

int main(void)
{
    char expression[101];
    printf("Введите выражение (до 100 символов):\n");
    if (scanf("%100[^\n]", expression) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    int len = strlen(expression);

    // вызов функции преобразования
    char* result = convertString(expression, len);

    if (result == NULL) {
        printf("ОШИБКА\n");
    } else {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
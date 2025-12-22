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
    Stack* stack = createStack();
    if (stack == NULL) {
        return NULL;
    }
    // каждый символ + пробел
    char* queue = malloc(len * 2 + 1);
    if (queue == NULL) {
        deleteStack(stack);
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
            push(stack, ch);
        } else if (ch == ')') {
            int top = 0;
            // если закрывающая скобка, вытягиваем из стека, пока не встретим '('
            while (!isEmpty(stack)) {
                peek(stack, &top);
                if (top == '(')
                    break;

                (char)pop(stack, (int*)(queue + (countForQueue++)));
                queue[countForQueue++] = ' ';
            }
            if (isEmpty(stack)) {
                deleteStack(stack);
                free(queue);
                return NULL;
            }
            pop(stack, &top); // удалить '('
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int top = 0;
            // если оператор, вытягиваем из стека все операторы с приоритетом >= текущего
            while (!isEmpty(stack)) {
                if (!peek(stack, &top))
                    break;
                peek(stack, &top);
                if (top == '(' || getPriority((char)top) < getPriority(ch))
                    break;
                pop(stack, &top);
                queue[countForQueue++] = (char)top;
                queue[countForQueue++] = ' ';
            }
            // помещаем текущий оператор в стек
            push(stack, ch);
        } else {
            // неожидаемый символ
            deleteStack(stack);
            free(queue);
            return NULL;
        }
        // переходим к следующему символу
        ++i;
    }

    int top = 0;
    // после обработки всей строки вытягиваем оставшиеся операторы из стека
    while (!isEmpty(stack)) {
        if (!pop(stack, &top))
            break;
        if (top == '(') {
            // осталась незакрытая скобка — ошибка
            deleteStack(stack);
            free(queue);
            return NULL;
        }
        queue[countForQueue++] = (char)top;
        queue[countForQueue++] = ' ';
    }

    deleteStack(stack);

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
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        printf("Ошибка ввода\n");
        return 1;
    }
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
        len--;
    }

    // вызов функции преобразования
    char* result = convertString(expression, (int)len);

    if (result == NULL) {
        printf("ОШИБКА\n");
    } else {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
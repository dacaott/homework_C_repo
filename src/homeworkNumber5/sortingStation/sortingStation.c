#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция определения приоритета оператора
int getPriority(char operand) {
  if (operand == '+' || operand == '-') {
    return 1; // низкий приоритет для + и -
  } else if (operand == '*' || operand == '/') {
    return 2; // высокий приоритет для * и /
  }
  return 0; // для других символов
}

// Функция преобразования инфиксного выражения в постфиксное
char *convertString(const char *string, int len) {
  struct Stack stack;
  initStack(&stack);                         // создаем пустой стек
  char *queue = malloc(1024 * sizeof(char)); // буфер для постфиксного выражения
  int countForQueue = 0;                     // текущий индекс в очереди
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
    } else if (ch == '(') {
      // если открывающая скобка, помещаем в стек
      push(&stack, (int)ch);
    } else if (ch == ')') {
      // если закрывающая скобка, вытягиваем из стека, пока не встретим '('
      while (!isEmpty(&stack) && peek(&stack) != '(') {
        queue[countForQueue++] = (char)pop(&stack);
      }
      if (!isEmpty(&stack) && peek(&stack) == '(') {
        // удаляем '(' из стека
        pop(&stack);
      } else {
        // не нашли '(' — ошибка
        deleteStack(&stack);
        free(queue);
        return strdup("ОШИБКА: пропущена открывающая скобка");
      }
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      // если оператор, вытягиваем из стека все операторы с приоритетом >=
      // текущего
      while (!isEmpty(&stack) &&
             getPriority((char)peek(&stack)) >= getPriority(ch) &&
             peek(&stack) != '(') {
        queue[countForQueue++] = (char)pop(&stack);
      }
      // помещаем текущий оператор в стек
      push(&stack, (int)ch);
    } else {
      // неожидаемый символ
      deleteStack(&stack);
      free(queue);
      return strdup("ОШИБКА: недопустимый символ");
    }
    ++i; // переходим к следующему символу
  }

  // после обработки всей строки вытягиваем оставшиеся операторы из стека
  while (!isEmpty(&stack)) {
    char topChar = (char)peek(&stack);
    if (topChar == '(') {
      // осталась незакрытая скобка — ошибка
      deleteStack(&stack);
      free(queue);
      return strdup("ОШИБКА: пропущена закрывающая скобка");
    }
    queue[countForQueue++] = (char)pop(&stack);
  }

  deleteStack(&stack);         // очищаем стек
  queue[countForQueue] = '\0'; // завершаем строку нулевым символом
  return queue;                // возвращаем постфиксное выражение
}

int main() {
  char *expression = malloc(101 * sizeof(char)); // буфер для входного выражения
  printf("Введите выражение (до 100 символов):\n");
  fgets(expression, 101, stdin); // чтение строки с клавиатуры

  size_t len = strlen(expression);
  if (len > 0 && expression[len - 1] == '\n') {
    // удаляем символ новой строки
    expression[len - 1] = '\0';
    len--;
  }

  // вызов функции преобразования
  char *result = convertString(expression, (int)len);
  if (strncmp(result, "ОШИБКА", 5) == 0) {
    // вывод ошибки
    printf("%s\n", result);
  } else {
    // вывод результата постфиксного выражения с разделителями
    for (int i = 0; i < (int)strlen(result); i++) {
      if (i == 0) {
        printf("%c", result[i]); // без пробела перед первым символом
      } else {
        printf(" %c", result[i]); // с пробелом перед остальными
      }
    }
    printf("\n");
  }

  // освобождение памяти
  free(expression);
  free(result);
  return 0;
}
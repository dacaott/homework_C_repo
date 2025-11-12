#include "stack.h"
#include <stdio.h>
#include <string.h>

// Функция проверки баланса скобок
bool isBalanced(const char *str) {
  Stack stack;
  initStack(&stack);

  for (int i = 0; str[i] != '\0'; i++) {
    char current = str[i];

    // Если открывающая скобка - добавляем в стек
    if (current == '(' | current == '[' | current == '{') {
      push(&stack, current);
    }
    // Если закрывающая скобка - проверяем соответствие
    else if (current == ')' | current == ']' | current == '}') {
      // Если стек пуст - несбалансировано
      if (isEmpty(&stack)) {
        deleteStack(&stack);
        return false;
      }

      char top = pop(&stack);

      // Проверяем соответствие скобок
      if ((current == ')' && top != '(') || (current == ']' && top != '[') ||
          (current == '}' && top != '{')) {
        deleteStack(&stack);
        return false;
      }
    }
  }

  // Если после обработки всей строки стек пуст - сбалансировано
  bool result = isEmpty(&stack);
  deleteStack(&stack);
  return result;
}

int main() {
  char input[256];

  printf("Введите строку для проверки баланса скобок: ");
  fgets(input, sizeof(input), stdin);

  // Убираем символ новой строки
  input[strcspn(input, "\n")] = '\0';

  if (isBalanced(input)) {
    printf("Скобки сбалансированы\n");
  } else {
    printf("Скобки НЕ сбалансированы\n");
  }

  return 0;
}
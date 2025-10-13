#include <stdio.h>
#include <string.h>

int main() {
  char str[256];

  printf("Введите строку: ");
  fgets(str, sizeof(str), stdin);

  size_t len = strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
    len--;
  }

  int left = 0;
  int right = len - 1;

  while (left < right) {
    // скипаем пробелы с левой стороны
    if (str[left] == ' ') {
      left++;
      continue;
    }
    // скипаем пробелы с правой стороны
    if (str[right] == ' ') {
      right--;
      continue;
    }
    // сравниваем
    if (str[left] != str[right]) {
      printf("Строка не является палиндромом.\n");
      return 0;
    }
    left++;
    right--;
  }

  printf("Строка является палиндромом.\n");
  return 0;
}

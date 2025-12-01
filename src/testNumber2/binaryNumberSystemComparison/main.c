#include "compareBinary.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  int lenA, lenB;

  // Ввод длины массива A
  scanf("%d", &lenA);

  bool a[lenA];
  // тут чтение битов массива A
  for (int i = 0; i < lenA; i++) {
    int bit;
    scanf("%d", &bit);         // ввод бита (0 или 1)
    a[i] = bit ? true : false; // преобразование в булев тип
  }

  // Ввод длины массива B
  scanf("%d", &lenB);

  bool b[lenB];
  // тут чтение битов массива B
  for (int i = 0; i < lenB; i++) {
    int bit;
    scanf("%d", &bit);         // ввод бита (0 или 1)
    b[i] = bit ? true : false; // преобразование в булев тип
  }

  // вызоваем функцию чтобы сравнить
  int result = compareBinary(a, lenA, b, lenB);

  if (result > 0) {
    printf("A > B\n");
  } else if (result < 0) {
    printf("A < B\n");
  } else {
    printf("A == B\n");
  }

  return 0;
}
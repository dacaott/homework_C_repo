#include <stdio.h>
#include <stdlib.h>

extern int bubbleSort(int *arr, int n); // объявление функции из sort.s

int main() {
  int arr[100];
  int orig[100]; // для сохранения исходного массива
  int n = 0;

  // Считываем числа до конца строки
  while (scanf("%d", &arr[n]) == 1) {
    orig[n] = arr[n];
    n++;
    if (n >= 100)
      break;
    if (getchar() == '\n')
      break;
  }

  // Вызов ассемблерной сортировки
  bubbleSort(arr, n);

  printf("Отсортированный массив: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  int changed = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != orig[i])
      changed++;
  }

  printf("Количество элементов, участвовавших в сортировке: %d\n", n);
  printf("Количество элементов, изменивших свою позицию: %d\n", changed);

  return changed;
}
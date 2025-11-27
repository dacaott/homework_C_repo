#include <stdio.h>

int countZeroElements(int array[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (array[i] == 0)
      count++;
  }

  return count;
}

int main(void) {
  int n = 0;
  int array[1000] = {0};

  printf("Введите количество элементов массива: ");
  scanf("%d", &n);

  printf("Введите элементы этого массива: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  int count = countZeroElements(array, n);

  printf("Количество нулевых элементов: %d\n", count);

  return 0;
}
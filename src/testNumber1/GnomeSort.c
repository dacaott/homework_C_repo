#include <stdio.h>

void gnomeSort(int arr[], int size) {
  int index = 0;
  while (index < size) {
    if (index == 0 || arr[index] >= arr[index - 1]) {
      // если текущий элемент в правильном порядке или на начале
      index++;
    } else {
      // меняю местами текущий и предыдущий элементы
      int temp = arr[index];
      arr[index] = arr[index - 1];
      arr[index - 1] = temp;
      index--;
    }
  }
}

int main() {
  int array[] = {5, 3, 8, 4, 2};
  int size = sizeof(array) / sizeof(array[0]);

  gnomeSort(array, size);

  printf("Отсортированный массив: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
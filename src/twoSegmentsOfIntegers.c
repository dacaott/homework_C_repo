#include <stdio.h>

void reverseSegment(int *array, int startIndex, int endIndex) {
  while (startIndex < endIndex) {
    int temp = array[startIndex];
    array[startIndex] = array[endIndex];
    array[endIndex] = temp;
    startIndex++;
    endIndex--;
  }
}

void swapTwoSegments(int *array, int firstSegmentLength,
                     int secondSegmentLength) {
  int totalLength = firstSegmentLength + secondSegmentLength;
  reverseSegment(array, 0, firstSegmentLength - 1);
  reverseSegment(array, firstSegmentLength, totalLength - 1);
  reverseSegment(array, 0, totalLength - 1);
}

int main() {
  int firstSegmentLength = 0;
  int secondSegmentLength = 0;

  printf("Введите длину первого сегмента массива (m): ");
  scanf("%d", &firstSegmentLength);

  printf("Введите длину второго сегмента массива (n): ");
  scanf("%d", &secondSegmentLength);

  int totalLength = firstSegmentLength + secondSegmentLength;
  int inputArray[totalLength];

  printf("Введите %d целых чисел массива через пробел:\n", totalLength);
  for (int i = 0; i < totalLength; ++i) {
    inputArray[i] = 0;
    scanf("%d", &inputArray[i]);
  }

  swapTwoSegments(inputArray, firstSegmentLength, secondSegmentLength);

  printf("Полученный массив:\n");
  for (int i = 0; i < totalLength; ++i) {
    printf("%d ", inputArray[i]);
  }
  printf("\n");

  return 0;
}
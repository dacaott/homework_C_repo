#include "sort.h"
#include <stdio.h>

int main()
{
    int numbers[100];
    int originalNumbers[100]; // для сохранения исходного массива
    int elementCount = 0;

    // Считываем числа до конца строки
    while (elementCount < 100 && scanf("%d", &numbers[elementCount]) == 1) {
        originalNumbers[elementCount] = numbers[elementCount];
        elementCount++;

        if (getchar() == '\n')
            break;
    }

    bubbleSort(numbers, elementCount);

    printf("Отсортированный массив: ");
    for (int index = 0; index < elementCount; index++) {
        printf("%d ", numbers[index]);
    }
    printf("\n");

    int changed = 0;
    for (int index = 0; index < elementCount; index++) {
        if (numbers[index] != originalNumbers[index])
            changed++;
    }

    printf("Количество элементов, участвовавших в сортировке: %d\n", elementCount);
    printf("Количество элементов, изменивших свою позицию: %d\n", changed);

    return changed;
}
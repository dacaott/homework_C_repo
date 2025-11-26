#include <stdio.h>

void gnomeSort(int e[], int size)
{
    int index = 0;
    while (index < size) {
        if (index == 0) {
            // На нулевой позиции всегда идем вперед
            index++;
        } else {
            // Проверяем порядок двух элементов
            if (e[index] >= e[index - 1]) {
                index++;
            } else {
                // Обмен элементов с использованием 'ф'
                int ф = e[index];
                e[index] = e[index - 1];
                e[index - 1] = ф;
                // Шаг назад
                index--;
            }
        }
    }
}

int main()
{
    int e[] = { 5, 3, 8, 4, 2 };
    int size = sizeof(e) / sizeof(e[0]);

    gnomeSort(e, size);

    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", e[i]);
    }
    printf("\n");
    return 0;
}
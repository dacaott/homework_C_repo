#include <stdio.h>

int main(void)
{
    int n = 0;
    int i = 0;
    int count = 0;
    int array[1000] = {0};

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    printf("Введите элементы этого массива: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++) {
        if (array[i] == 0)
            count++;
    }

    printf("Количество нулевых элементов: %d\n", count);

    return 0;
}
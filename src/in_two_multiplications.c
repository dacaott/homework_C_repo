#include <stdio.h>

int main() {
    int x;
    int a, res;

    printf("Введите число x: ");
    scanf("%d", &x);

    a = x * x;
    res = (a + 1) * (a + x) + 1;

    printf("Результат: %d\n", res);
    return 0;
}
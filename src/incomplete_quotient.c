#include <stdio.h>

int divide(int a, int b) {
    int quotient = 0;
    int sign = 1;

    if (a < 0) {
        a = -a;
        sign = -sign;
    }
    if (b < 0) {
        b = -b;
        sign = -sign;
    }

    if (b == 0) {
        return 0; 
    }

    while (a >= b) {
        a = a - b;
        quotient = quotient + 1;
    }

    if (sign < 0)
        quotient = -quotient;

    return quotient;
}

int main() {
    int a, b, result;

    printf("Число a: ");
    scanf("%d", &a);

    printf("Число b: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Ошибка: деление на ноль.\n");
        return 1;
    }

    result = divide(a, b);

    printf("%d / %d = %d\n", a, b, result);

    return 0;
}
#include <stdio.h>

int multiply(int a, int b)
{
    int result = 0;

    for (int i = 0; i < b; i++) {
        result += a;
    }

    if (result > 100) {
        printf("big number: %d\n", result);
    } else {
        printf("small:%d\n", result);
    }

    return result;
}

void printTable()
{
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("%3d ", multiply(i, j));
        }
        printf("\n");
    }
}

int main()
{
    printTable();
    return 0;
}
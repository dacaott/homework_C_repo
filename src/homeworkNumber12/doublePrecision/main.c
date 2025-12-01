#include "double.h"
#include <stdio.h>

int main()
{
    double userNumber;
    printf("Enter a number: ");
    scanf("%lf", &userNumber);

    // печать числа в формате (+-)m*2^p
    printDouble(userNumber);

    return 0;
}
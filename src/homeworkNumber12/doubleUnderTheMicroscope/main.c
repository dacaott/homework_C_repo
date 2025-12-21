#include "double.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double userNumber = 0;
    printf("Enter a number: ");
    scanf("%lf", &userNumber);

    // печать числа в формате (+-)m*2^p
    printDouble(userNumber);

    return 0;
}
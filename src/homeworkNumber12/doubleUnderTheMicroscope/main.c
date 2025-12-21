#include "double.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[64];
    double userNumber = 0;
    printf("Enter a number: ");

    if (!fgets(input, sizeof(input), stdin)) {
        // безопасный вывод
        fputs("Input error\n", stderr);
        return 1;
    }

    char* end;
    userNumber = strtod(input, &end);

    // проверяем, что введено именно число и нет др символов
    if (end == input || (*end != '\n' && *end != '\0')) {
        // и тут тоже безопасный вывод
        fputs("Invalid number\n", stderr);
        return 1;
    }

    printf("%f\n", userNumber);

    return 0;
}
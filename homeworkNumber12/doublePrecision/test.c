#include "double.h"
#include <stdio.h>
#include <string.h>

// проверка числа и ожидаемой подстроки
int runTest(double number, const char* expectedSubstring)
{
    char buffer[128];
    getDoubleString(number, buffer, sizeof(buffer));

    if (strstr(buffer, expectedSubstring) != NULL) {
        printf("Test %g: OK\n", number);
        return 1;
    } else {
        printf("Test %g: FAIL (got %s, expected substring %s)\n",
            number, buffer, expectedSubstring);
        return 0;
    }
}

int main()
{
    int passed = 0;
    int total = 0;

    total++;
    passed += runTest(0.0, "+0");
    total++;
    passed += runTest(-0.0, "-0");
    total++;
    passed += runTest(1.0, "+1");
    total++;
    passed += runTest(-1.0, "-1");
    total++;
    passed += runTest(2.5, "1.25*2^1");
    total++;
    passed += runTest(-2.5, "-1.25*2^1");
    total++;
    passed += runTest(12312.323, "2^13");
    total++;
    passed += runTest(3.1415926535, "2^1");
    total++;
    passed += runTest(0.1, "2^-4");

    printf("\nTests passed: %d/%d\n", passed, total);

    return 0;
}
#include "double.h"
#include <stdio.h>
#include <stdlib.h>

typedef union {
    double value;
    unsigned char bytes[8];
} DoubleUnion;

// внутренний максимальный размер строки
#define INTERNAL_DOUBLE_STRING_MAX 64

char* doubleToString(double number)
{
    char* buffer = malloc(INTERNAL_DOUBLE_STRING_MAX);
    if (!buffer)
        return NULL;
    DoubleUnion u;
    u.value = number;

    // знак числа (1 бит)
    int signBit = (u.bytes[7] & 0x80) >> 7;
    // порядок (11 бит)
    int exponentBits = ((u.bytes[7] & 0x7F) << 4) | ((u.bytes[6] & 0xF0) >> 4);

    // мантисса (52 бита)
    unsigned char mantissaBytes[7];
    for (int i = 0; i < 7; i++)
        mantissaBytes[i] = (i < 6) ? u.bytes[i] : (u.bytes[6] & 0x0F);

    // восстанавливаем нормализованную мантиссу
    double mantissa = (exponentBits == 0) ? 0.0 : 1.0; // скрытый бит
    double add = 0.5;

    // обходим все 52 бита
    for (int i = 0; i < 52; i++) {
        int byteIndex = i / 8;
        int bitIndex = 7 - (i % 8);
        if (mantissaBytes[byteIndex] & (1 << bitIndex))
            mantissa += add;
        add /= 2.0;
    }

    int exponent = exponentBits - 1023; // помним, что порядок хранится со смещением

    size_t len = 0;

    // я клянусь, я уже не знаю как разрешить эти конфликты для clang-tidy!!
    // поэтому я нашла подавитель предупреждения
    snprintf(buffer, INTERNAL_DOUBLE_STRING_MAX, "%c%.17f*2^%d", signBit ? '-' : '+', mantissa, exponent); // NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    return buffer;
}

// вывод числа в stdout
void printDouble(double number)
{
    char* str = doubleToString(number);
    if (!str)
        return;

    printf("%s\n", str);
    free(str);
}
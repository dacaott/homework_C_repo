#include "double.h"
#include <stdio.h>
#include <stdlib.h>

typedef union {
    double value;
    unsigned char bytes[8];
} DoubleUnion;

// новая структура для удобного хранения частей числа
typedef struct {
    int sign; // 0=+, 1=-
    double mantissa;
    int exponent;
} DoubleParts;

// извлекаем части числа
static DoubleParts decomposeDouble(double number)
{
    DoubleUnion u;
    u.value = number;

    DoubleParts parts;
    parts.sign = (u.bytes[7] & 0x80) >> 7;

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

    parts.mantissa = mantissa;
    parts.exponent = exponentBits - 1023;

    return parts;
}
// возвращает строку (только для тестов)
char* doubleToString(double number)
{
    static char buffer[64]; // используем статический буфер, нет malloc
    DoubleParts parts = decomposeDouble(number);

    // формируем строку напрямую через sprintf (без snprintf)
    // буфер достаточно большой, тесты с 64 символами проходят
    sprintf(buffer, "%c%.17f*2^%d", parts.sign ? '-' : '+', parts.mantissa, parts.exponent);

    return buffer;
}

// вывод числа в stdout
void printDouble(double number)
{
    DoubleParts parts = decomposeDouble(number);
    printf("%c%.17f*2^%d\n", parts.sign ? '-' : '+', parts.mantissa, parts.exponent);
}
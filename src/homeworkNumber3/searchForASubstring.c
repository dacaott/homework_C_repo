#include <stdio.h>
#include <string.h>

int countSubstringOccurrences(char s[], char s1[])
{
    int count = 0;
    int lens = strlen(s);
    int lens1 = strlen(s1);

    for (int i = 0; i <= lens - lens1; i++) {
        if (strncmp(&s[i], s1, lens1) == 0)
            count++;
    }

    return count;
}
int main(void)
{
    char s[1000] = { 0 };
    char s1[1000] = { 0 };

    printf("Введите строку S: ");
    scanf("%s", s);

    printf("Введите подстроку S1: ");
    scanf("%s", s1);

    int count = countSubstringOccurrences(s, s1);

    printf("Количество вхождений подстроки: %d\n", count);

    return 0;
}
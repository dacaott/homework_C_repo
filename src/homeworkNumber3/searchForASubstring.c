#include <stdio.h>
#include <string.h>

int countSubstringOccurrences(char S[], char S1[])
{
    int count = 0;
    int lenS = (int)strlen(S);
    int lenS1 = (int)strlen(S1);

    for (int i = 0; i <= lenS - lenS1; i++) {
        if (strncmp(&S[i], S1, lenS1) == 0)
            count++;
    }

    return count;
}
int main(void)
{
    char S[1000] = { 0 };
    char S1[1000] = { 0 };

    printf("Введите строку S: ");
    scanf("%s", S);

    printf("Введите подстроку S1: ");
    scanf("%s", S1);

    int count = countSubstringOccurrences(S, S1);

    printf("Количество вхождений подстроки: %d\n", count);

    return 0;
}
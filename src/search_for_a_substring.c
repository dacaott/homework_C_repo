#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[1000] = {0};
    char S1[1000] = {0};
    int i = 0;
    int count = 0;
    int lenS = 0;
    int lenS1 = 0;

    printf("Введите строку S: ");
    scanf("%s", S);

    printf("Введите подстроку S1: ");
    scanf("%s", S1);

    lenS = (int)strlen(S);
    lenS1 = (int)strlen(S1);

    for (i = 0; i <= lenS - lenS1; i++) {
        if (strncmp(&S[i], S1, lenS1) == 0)
            count++;
    }

    printf("Количество вхождений подстроки: %d\n", count);

    return 0;
}
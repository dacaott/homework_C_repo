#include <stdio.h>

int main(void)
{
    char str[1000] = {0};
    int i = 0;
    int balance = 0;
    int isBalanced = 1;

    printf("Введите строку: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')') {
            balance--;
            if (balance < 0) {
                isBalanced = 0;
                break;
            }
        }
    }

    if (balance != 0)
        isBalanced = 0;

    if (isBalanced)
        printf("Скобки сбалансированы.\n");
    else
        printf("Скобки НЕ сбалансированы.\n");

    return 0;
}
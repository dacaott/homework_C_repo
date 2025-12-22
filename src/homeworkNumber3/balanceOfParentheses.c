#include <stdbool.h>
#include <stdio.h>

bool checkBalance(char str[])
{
    int balance = 0;
    bool isBalanced = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')') {
            balance--;
            if (balance < 0) {
                isBalanced = false;
                break;
            }
        }
    }

    if (balance != 0)
        isBalanced = false;

    return isBalanced;
}
int main(void)
{
    char str[1000] = { 0 };

    printf("Введите строку: ");
    scanf("%s", str);

    bool isBalanced = checkBalance(str);

    if (isBalanced)
        printf("Скобки сбалансированы.\n");
    else
        printf("Скобки НЕ сбалансированы.\n");

    return 0;
}
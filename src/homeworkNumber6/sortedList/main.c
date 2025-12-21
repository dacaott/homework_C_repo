#include "sortedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int readInt(const char* prompt, int* out)
{
    int n = 0;
    printf("%s", prompt);

    while (scanf("%d", &n) != 1) {
        printf("Некорректный ввод. Попробуйте снова: ");
        // сбрасываем остаток строки до конца
        int ch = 0;
        while ((ch = getchar()) != '\n') {
            // Просто пропускаем символы
        }
    }

    // очистка остатка строки после успешного ввода
    int ch = 0;
    while ((ch = getchar()) != '\n') {
        // просто пропускаем символы
    }
    *out = n;
    return 1;
}

int main(void)
{
    SortedList* list = createList();
    if (list == NULL) {
        printf("Ошибка: не удалось создать список.\n");
        return 1;
    }

    int cmd = 0, val = 0;
    printf("Программа работы с сортированным списком\n");

    while (1) {
        printf("\nМеню:\n");
        printf("0 – выйти\n");
        printf("1 – добавить значение\n");
        printf("2 – удалить значение\n");
        printf("3 – распечатать список\n");

        readInt("Ваш выбор: ", &cmd);

        switch (cmd) {

        case 1:
            readInt("Введите число для добавления: ", &val);
            if (addSorted(list, val))
                printf("Элемент %d добавлен.\n", val);
            else
                printf("Ошибка: не удалось выделить память.\n");
            break;

        case 2:
            readInt("Введите число для удаления: ", &val);
            if (deleteValue(list, val))
                printf("Элемент %d удалён.\n", val);
            else
                printf("Элемент %d не найден.\n", val);
            break;

        case 3:
            printList(list);
            break;

        case 0:
            printf("Выход...\n");
            freeList(list);
            return 0;

        default:
            printf("Неизвестная команда.\n");
        }
    }

    freeList(list);
    return 0;
}
#include "sortedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int readInt(const char* prompt, int* out)
{
    char buffer[64];
    char* endptr;
    long value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            // ошибка ввода
            continue;
        }

        value = strtol(buffer, &endptr, 10);

        // если strtol ничего не прочитал, повторяем
        if (endptr == buffer) {
            printf("Некорректный ввод. Попробуйте снова.\n");
            continue;
        }
        *out = (int)value;
        return 1;
    }
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
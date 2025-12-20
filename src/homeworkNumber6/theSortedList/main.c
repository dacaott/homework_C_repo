#include "sortedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Node* head = NULL;
    int cmd, val;
    char buffer[64];

    printf("Программа работы с сортированным списком\n");

    while (1) {
        printf("\nМеню:\n");
        printf("0 – выйти\n");
        printf("1 – добавить значение\n");
        printf("2 – удалить значение\n");
        printf("3 – распечатать список\n");
        printf("Ваш выбор: ");

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Ошибка ввода.\n");
            continue;
        }

        char* endptr;
        long tmp = strtol(buffer, &endptr, 10);
        if (endptr == buffer || (*endptr != '\n' && *endptr != '\0') || tmp < INT_MIN || tmp > INT_MAX) {
            printf("Некорректный ввод.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        cmd = (int)tmp;

        switch (cmd) {
        case 1:
            printf("Введите число для добавления: ");
            if (!fgets(buffer, sizeof(buffer), stdin)) {
                continue;
            }
            tmp = strtol(buffer, &endptr, 10);
            if (endptr == buffer || (*endptr != '\n' && *endptr != '\0') || tmp < INT_MIN || tmp > INT_MAX) {
                printf("Некорректный ввод.\n");
                continue;
            }
            val = (int)tmp;
            addSorted(&head, val);
            break;
        case 2:
            printf("Введите число для удаления: ");
            if (!fgets(buffer, sizeof(buffer), stdin)) {
                printf("Ошибка ввода.\n");
                continue;
            }
            tmp = strtol(buffer, &endptr, 10);
            if (endptr == buffer || (*endptr != '\n' && *endptr != '\0') || tmp < INT_MIN || tmp > INT_MAX) {
                printf("Некорректный ввод.\n");
                continue;
            }
            val = (int)tmp;
            deleteValue(&head, val);
            break;
        case 3:
            printList(head);
            break;
        case 0:
            printf("Выход...\n");
            freeList(head);
            return 0;
        default:
            printf("Неизвестная команда.\n");
        }
    }

    freeList(head);
    return 0;
}
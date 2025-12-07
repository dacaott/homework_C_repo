#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Node* head = NULL;
    int cmd, val;
    char buffer[32];

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
            break;
        }

        if (sscanf(buffer, "%d", &cmd) != 1) {
            printf("Некорректный ввод.\n");
            continue;
        }

        switch (cmd) {
        case 1:
            printf("Введите число для добавления: ");
            if (!fgets(buffer, sizeof(buffer), stdin) || sscanf(buffer, "%d", &val) != 1) {
                printf("Ошибка ввода.\n");
                continue;
            }
            addSorted(&head, val);
            break;
        case 2:
            printf("Введите число для удаления: ");
            if (scanf("%d", &val) == 1)
                deleteValue(&head, val);
            else
                printf("Ошибка ввода.\n");
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

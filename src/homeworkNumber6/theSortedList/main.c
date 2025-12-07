#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Node* head = NULL;
    int cmd, val;

    printf("Программа работы с сортированным списком\n");

    while (1) {
        printf("\nМеню:\n");
        printf("0 – выйти\n");
        printf("1 – добавить значение\n");
        printf("2 – удалить значение\n");
        printf("3 – распечатать список\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &cmd) != 1) { // NOLINT(cert-err34-c)
            printf("Некорректный ввод.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (cmd) {
        case 1:
            printf("Введите число для добавления: ");
            if (scanf("%d", &val) == 1) // NOLINT(cert-err34-c)
                addSorted(&head, val);
            else {
                printf("Ошибка ввода.\n");
                while (getchar() != '\n')
                    ;
            }
            break;
        case 2:
            printf("Введите число для удаления: ");
            if (scanf("%d", &val) == 1) // NOLINT(cert-err34-c)
                deleteValue(&head, val);
            else {
                printf("Ошибка ввода.\n");
                while (getchar() != '\n')
                    ;
            }
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

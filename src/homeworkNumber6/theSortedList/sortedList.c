#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

void add_sorted(Node** head, int val)
{
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка: не удалось выделить память.\n");
        return;
    }
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL || val < (*head)->value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* cur = *head;
    while (cur->next != NULL && cur->next->value < val)
        cur = cur->next;

    newNode->next = cur->next;
    cur->next = newNode;
}

void delete_value(Node** head, int val)
{
    if (*head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    Node *cur = *head, *prev = NULL;

    while (cur != NULL && cur->value != val) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Элемент %d не найден.\n", val);
        return;
    }

    if (prev == NULL)
        *head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
    printf("Элемент %d удалён.\n", val);
}

void print_list(Node* head)
{
    if (!head) {
        printf("Список пуст.\n");
        return;
    }
    printf("Список: ");
    for (Node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->value);
    printf("\n");
}

void free_list(Node* head)
{
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

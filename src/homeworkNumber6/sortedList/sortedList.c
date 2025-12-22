#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

struct SortedList {
    Node* head;
};

SortedList* createList(void)
{
    SortedList* list = malloc(sizeof(SortedList));
    if (list == NULL)
        return NULL;
    list->head = NULL;
    return list;
}

bool addSorted(SortedList* list, int val)
{
    if (list == NULL)
        return false;

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return false;

    newNode->value = val;
    newNode->next = NULL;

    if (!list->head || val < list->head->value) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }

    Node* cur = list->head;
    while (cur->next && cur->next->value < val)
        cur = cur->next;

    newNode->next = cur->next;
    cur->next = newNode;
    return true;
}

bool deleteValue(SortedList* list, int val)
{
    if (!list || !list->head)
        return false;

    Node* cur = list->head;
    Node* prev = NULL;

    while (cur && cur->value != val) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        return false;
    }

    if (prev == NULL)
        list->head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
    return true;
}

void printList(const SortedList* list)
{
    if (!list || !list->head) {
        printf("Список пуст.\n");
        return;
    }
    printf("Список: ");
    for (Node* cur = list->head; cur; cur = cur->next)
        printf("%d ", cur->value);
    printf("\n");
}

void freeList(SortedList* list)
{
    if (list == NULL)
        return;

    Node* cur = list->head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(list);
}

int toArray(const SortedList* list, int* arr, int maxSize)
{
    if (!list)
        return 0;
    int count = 0;
    Node* cur = list->head;
    while (cur && count < maxSize) {
        arr[count++] = cur->value;
        cur = cur->next;
    }
    return count;
}
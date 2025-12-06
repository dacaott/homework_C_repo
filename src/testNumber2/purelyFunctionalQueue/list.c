#include "list.h"

ListNode* listPrepend(int value, ListNode* tail) {
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = tail; // последние строки
    return node;
}

ListNode* listReverse(ListNode* list) {
    ListNode* result = NULL;
    while (list != NULL) {
        result = listPrepend(list->value, result);
        list = list->next;
    }
    return result;
}

void listFree(ListNode* list) {
    while (list != NULL) {
        ListNode* next = list->next;
        free(list);
        list = next;
    }
}

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// узел односвязного (иммутабельного) списка 
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

// создание нового узла (голова возвращаемого списка)
ListNode* listPrepend(int value, ListNode* tail);

// реверс (создаёт новый список!)
ListNode* listReverse(ListNode* list);

// освобождение списка (подчистую)
void listFree(ListNode* list);

#endif
#ifndef SORTEDLIST_H
#define SORTEDLIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void addSorted(Node** head, int val);
void deleteValue(Node** head, int val);
void printList(Node* head);
void freeList(Node* head);

#endif
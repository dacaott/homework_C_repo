#ifndef SORTEDLIST_H
#define SORTEDLIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void add_sorted(Node** head, int val);
void delete_value(Node** head, int val);
void print_list(Node* head);
void free_list(Node* head);

#endif
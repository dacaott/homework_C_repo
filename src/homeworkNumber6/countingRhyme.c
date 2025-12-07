#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* next;
} Node;

int main(void)
{
    int n, m;
    printf("Введите n (число воинов) и m (шаг убийства): ");
    if (scanf("%d %d", &n, &m) != 2 | n <= 0 | m <= 0) {
        printf("Некорректный ввод.\n");
        return 1;
    }

    // создаём циклический список из n узлов
    Node* head = malloc(sizeof(Node));
    head->id = 1;
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* p = malloc(sizeof(Node));
        p->id = i;
        prev->next = p;
        prev = p;
    }
    prev->next = head; // замыкаем круг

    // начинаем "считалочку"
    Node* cur = prev; // текущий указывает на предыдущего
    while (cur->next != cur) {
        for (int i = 1; i < m; i++) {
            cur = cur->next; // считаем m-1 воинов
        }
        Node* dead = cur->next; // убиваем следующего
        cur->next = dead->next; // пропускаем убитого
        free(dead); // освобождаем память
    }

    printf("Выживший воин находится на позиции: %d\n", cur->id);
    free(cur);
    return 0;
}
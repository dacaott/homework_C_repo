#include "sortedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool testEmptyList()
{
    Node* head = NULL;
    addSorted(&head, 5);
    bool result = (head != NULL && head->value == 5 && head->next == NULL);
    freeList(head);
    return result;
}

bool testInsertBeginning()
{
    Node* head = NULL;
    addSorted(&head, 10);
    addSorted(&head, 5);
    bool result = false;
    if (head && head->next) {
        result = (head->value == 5 && head->next->value == 10 && head->next->next == NULL);
    }
    freeList(head);
    return result;
}

bool testInsertEnd()
{
    Node* head = NULL;
    addSorted(&head, 5);
    addSorted(&head, 10);
    bool result = false;
    if (head && head->next) {
        result = (head->value == 5 && head->next->value == 10 && head->next->next == NULL);
    }
    freeList(head);
    return result;
}

bool testInsertMiddle()
{
    Node* head = NULL;
    addSorted(&head, 5);
    addSorted(&head, 15);
    addSorted(&head, 10);

    bool result = false;
    if (head && head->next && head->next->next) {
        result = (head->value == 5 && head->next->value == 10 && head->next->next->value == 15 && head->next->next->next == NULL);
    }
    freeList(head);
    return result;
}

bool testDeleteBeginning()
{
    Node* head = NULL;
    addSorted(&head, 5);
    addSorted(&head, 10);
    deleteValue(&head, 5);
    bool result = false;
    if (head && head->next == NULL) {
        result = (head->value == 10);
    }
    freeList(head);
    return result;
}

bool testDeleteEnd()
{
    Node* head = NULL;
    addSorted(&head, 5);
    addSorted(&head, 10);
    deleteValue(&head, 10);
    bool result = false;
    if (head && head->next == NULL) {
        result = (head->value == 5);
    }
    freeList(head);
    return result;
}

bool testSortedProperty()
{
    Node* head = NULL;
    addSorted(&head, 3);
    addSorted(&head, 1);
    addSorted(&head, 2);

    bool sorted = true;
    for (Node* cur = head; cur && cur->next; cur = cur->next) {
        if (cur->value > cur->next->value) {
            sorted = false;
            break;
        }
    }

    if (!(head && head->next && head->next->next)) {
        freeList(head);
        return false;
    }

    bool result = sorted && head->value == 1 && head->next->value == 2 && head->next->next->value == 3;
    freeList(head);
    return result;
}

void runTests()
{
    printf("=== ТЕСТИРОВАНИЕ СОРТИРОВАННОГО СПИСКА ===\n\n");

    struct {
        const char* name;
        bool (*testFunc)();
    } tests[] = {
        { "Добавление в пустой список", testEmptyList },
        { "Добавление в начало", testInsertBeginning },
        { "Добавление в конец", testInsertEnd },
        { "Добавление в середину", testInsertMiddle },
        { "Удаление из начала", testDeleteBeginning },
        { "Удаление из конца", testDeleteEnd },
        { "Сохранение сортированности", testSortedProperty },
    };

    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < total; i++) {
        printf("Тест %d: %s... ", i + 1, tests[i].name);
        bool result = tests[i].testFunc();

        if (result) {
            printf("ПРОЙДЕН\n");
            passed++;
        } else {
            printf("НЕ ПРОЙДЕН\n");
        }
    }

    printf("\nРезультат: %d/%d тестов пройдено\n", passed, total);

    if (passed == total) {
        printf("Все тесты успешно пройдены!\n");
    } else {
        printf("Некоторые тесты не пройдены!\n");
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        runTests();
        return 0;
    }

    printf("Используйте --test для запуска тестов\n");
    return 0;
}
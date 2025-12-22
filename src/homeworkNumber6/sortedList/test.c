#include "sortedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

bool testEmptyList()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 5);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = (n == 1 && arr[0] == 5);
    freeList(list);
    return result;
}

bool testInsertBeginning()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 10);
    addSorted(list, 5);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = (n == 2 && arr[0] == 5 && arr[1] == 10);
    freeList(list);
    return result;
}

bool testInsertEnd()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 5);
    addSorted(list, 10);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = (n == 2 && arr[0] == 5 && arr[1] == 10);
    freeList(list);
    return result;
}

bool testInsertMiddle()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 5);
    addSorted(list, 15);
    addSorted(list, 10);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = (n == 3 && arr[0] == 5 && arr[1] == 10 && arr[2] == 15);
    freeList(list);
    return result;
}

bool testDeleteBeginning()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 5);
    addSorted(list, 10);
    bool deleted = deleteValue(list, 5);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = deleted && (n == 1 && arr[0] == 10);
    freeList(list);
    return result;
}

bool testDeleteEnd()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 5);
    addSorted(list, 10);
    bool deleted = deleteValue(list, 10);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool result = deleted && (n == 1 && arr[0] == 5);
    freeList(list);
    return result;
}

bool testSortedProperty()
{
    SortedList* list = createList();
    if (!list)
        return false;

    addSorted(list, 3);
    addSorted(list, 1);
    addSorted(list, 2);

    int arr[MAX_SIZE];
    int n = toArray(list, arr, MAX_SIZE);

    bool sorted = (n == 3 && arr[0] == 1 && arr[1] == 2 && arr[2] == 3);
    freeList(list);
    return sorted;
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
    runTests();
    return 0;
}

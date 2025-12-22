#pragma once
#include <stdbool.h>

typedef struct SortedList SortedList;

// Создаёт новый пустой сортированный список
// и возвращает указатель на список или NULL, если не удалось выделить память
SortedList* createList(void);

// Добавляет значение в сортированный список
// и возвращает true, если успешно, false при ошибке памяти
bool addSorted(SortedList* list, int val);

// Удаляет значение из списка
// и возвращает true, если элемент был найден и удалён, false если не найден
bool deleteValue(SortedList* list, int val);

void printList(const SortedList* list);

void freeList(SortedList* list);

#ifdef TEST
// Копирует элементы списка в массив arr
// и возвращает количество элементов в списке (не больше maxSize)
int toArray(const SortedList* list, int* arr, int maxSize);
#endif
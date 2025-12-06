#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

// очередь из списков f (front) и r (rear)
typedef struct {
  ListNode *f;
  ListNode *r;
} Queue;

// создание пустой очереди
Queue queueEmpty();

// добавление элемента
Queue enqueue(Queue q, int value);

// удаление элемента (возвращает новую очередь)
Queue dequeue(Queue q);

// получение головы очереди (без удаления)
int queueFront(Queue q);

// проверка пустоты
int queueIsEmpty(Queue q);

// освободить полностью очередь
void queueFree(Queue q);

#endif

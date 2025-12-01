#include "queue.h"

// восстановление инварианта: если f пуст, перевернуть r
static Queue queueNormalize(Queue q) {
  if (q.f == NULL && q.r != NULL) {
    q.f = listReverse(q.r);
    q.r = NULL;
  }
  return q;
}

Queue queueEmpty() {
  Queue q = {NULL, NULL};
  return q;
}

Queue enqueue(Queue q, int value) {
  q.r = listPrepend(value, q.r);
  return queueNormalize(q);
}

Queue dequeue(Queue q) {
  if (q.f == NULL)
    return q; // пустая очередь — без изменений

  ListNode *next = q.f->next;
  free(q.f); // удаляем голову
  q.f = next;

  return queueNormalize(q);
}

int queueFront(Queue q) {
  if (q.f == NULL) {
    // если ннеправильный вызов — пустая очередь
    return 0;
  }
  return q.f->value;
}

int queueIsEmpty(Queue q) { return q.f == NULL && q.r == NULL; }

void queueFree(Queue q) {
  listFree(q.f);
  listFree(q.r);
}

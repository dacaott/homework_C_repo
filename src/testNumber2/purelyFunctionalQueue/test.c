#include <stdio.h>
#include "queue.h"


int main() {
    Queue q = queueEmpty();

    // enqueue 1..6
    for (int i = 1; i <= 6; i++) {
        q = enqueue(q, i);
    }

    // проверяем порядок 
    for (int expected = 1; expected <= 6; expected++) {
        if (queueFront(q) != expected) {
            printf("Test FAILED: expected %d got %d\n",
                   expected, queueFront(q));
            return 1;
        }
        q = dequeue(q);
    }

    if (!queueIsEmpty(q)) {
        printf("Test FAILED: queue should be empty\n");
        return 1;
    }

    printf("All tests passed!\n");
    queueFree(q);
    return 0;
}

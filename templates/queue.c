#include "queue.h"
#include <stdlib.h>

struct Queue {
    // TODO: Define your queue structure
};

Queue* queue_create(void) {
    return NULL;
}

void queue_enqueue(Queue *q, int value) {
    (void)q;
    (void)value;
}

int queue_dequeue(Queue *q) {
    (void)q;
    return 0;
}

int queue_peek(const Queue *q) {
    (void)q;
    return 0;
}

bool queue_is_empty(const Queue *q) {
    (void)q;
    return true;
}

size_t queue_size(const Queue *q) {
    (void)q;
    return 0;
}

void queue_destroy(Queue *q) {
    (void)q;
}

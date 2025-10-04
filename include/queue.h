#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Queue Queue;

Queue* queue_create(void);
void queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q);
int queue_peek(const Queue *q);
bool queue_is_empty(const Queue *q);
size_t queue_size(const Queue *q);
void queue_destroy(Queue *q);

#endif // QUEUE_H

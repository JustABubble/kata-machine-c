#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct MinHeap MinHeap;

MinHeap* min_heap_create(void);
void min_heap_insert(MinHeap *heap, int value);
int min_heap_extract_min(MinHeap *heap);  // Returns minimum and removes it
int min_heap_peek_min(const MinHeap *heap);  // Returns minimum without removing
bool min_heap_is_empty(const MinHeap *heap);
size_t min_heap_size(const MinHeap *heap);
void min_heap_destroy(MinHeap *heap);

#endif // MIN_HEAP_H

#ifndef LRU_H
#define LRU_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LRU LRU;

// Create an LRU cache with specified capacity
LRU* lru_create(size_t capacity);

// Get a value by key (returns -1 if not found, updates as most recently used)
int lru_get(LRU *cache, int key);

// Put a key-value pair (evicts least recently used if at capacity)
void lru_put(LRU *cache, int key, int value);

// Check if key exists
bool lru_contains(const LRU *cache, int key);

// Get current size
size_t lru_size(const LRU *cache);

// Destroy the cache
void lru_destroy(LRU *cache);

#endif // LRU_H

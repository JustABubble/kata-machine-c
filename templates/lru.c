#include "lru.h"
#include <stdlib.h>

struct LRU {
    // TODO: Define your LRU cache structure
};

LRU* lru_create(size_t capacity) {
    (void)capacity;
    return NULL;
}

int lru_get(LRU *cache, int key) {
    (void)cache;
    (void)key;
    return -1;
}

void lru_put(LRU *cache, int key, int value) {
    (void)cache;
    (void)key;
    (void)value;
}

bool lru_contains(const LRU *cache, int key) {
    (void)cache;
    (void)key;
    return false;
}

size_t lru_size(const LRU *cache) {
    (void)cache;
    return 0;
}

void lru_destroy(LRU *cache) {
    (void)cache;
}

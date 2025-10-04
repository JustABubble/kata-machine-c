#include "map.h"
#include <stdlib.h>

struct Map {
    // TODO: Define your hash map structure
};

Map* map_create(void) {
    return NULL;
}

void map_put(Map *map, int key, int value) {
    (void)map;
    (void)key;
    (void)value;
}

int map_get(const Map *map, int key) {
    (void)map;
    (void)key;
    return -1;
}

bool map_contains(const Map *map, int key) {
    (void)map;
    (void)key;
    return false;
}

void map_remove(Map *map, int key) {
    (void)map;
    (void)key;
}

size_t map_size(const Map *map) {
    (void)map;
    return 0;
}

void map_destroy(Map *map) {
    (void)map;
}

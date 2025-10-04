#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Map Map;

Map* map_create(void);
void map_put(Map *map, int key, int value);
int map_get(const Map *map, int key);  // Returns -1 if not found
bool map_contains(const Map *map, int key);
void map_remove(Map *map, int key);
size_t map_size(const Map *map);
void map_destroy(Map *map);

#endif // MAP_H

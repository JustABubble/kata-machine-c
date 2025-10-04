#include "array_list.h"
#include <stdlib.h>

struct ArrayList {
    // TODO: Define your dynamic array structure
};

ArrayList* array_list_create(void) {
    return NULL;
}

void array_list_append(ArrayList *list, int value) {
    (void)list;
    (void)value;
}

void array_list_insert_at(ArrayList *list, size_t index, int value) {
    (void)list;
    (void)index;
    (void)value;
}

int array_list_remove_at(ArrayList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

int array_list_get(const ArrayList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

void array_list_set(ArrayList *list, size_t index, int value) {
    (void)list;
    (void)index;
    (void)value;
}

size_t array_list_size(const ArrayList *list) {
    (void)list;
    return 0;
}

size_t array_list_capacity(const ArrayList *list) {
    (void)list;
    return 0;
}

void array_list_destroy(ArrayList *list) {
    (void)list;
}

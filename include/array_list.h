#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ArrayList ArrayList;

ArrayList* array_list_create(void);
void array_list_append(ArrayList *list, int value);
void array_list_insert_at(ArrayList *list, size_t index, int value);
int array_list_remove_at(ArrayList *list, size_t index);
int array_list_get(const ArrayList *list, size_t index);
void array_list_set(ArrayList *list, size_t index, int value);
size_t array_list_size(const ArrayList *list);
size_t array_list_capacity(const ArrayList *list);
void array_list_destroy(ArrayList *list);

#endif // ARRAY_LIST_H

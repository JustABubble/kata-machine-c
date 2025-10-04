#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct SinglyLinkedList SinglyLinkedList;

SinglyLinkedList* singly_linked_list_create(void);
void singly_linked_list_prepend(SinglyLinkedList *list, int value);
void singly_linked_list_append(SinglyLinkedList *list, int value);
void singly_linked_list_insert_at(SinglyLinkedList *list, size_t index, int value);
int singly_linked_list_remove(SinglyLinkedList *list, int value);
int singly_linked_list_remove_at(SinglyLinkedList *list, size_t index);
int singly_linked_list_get(const SinglyLinkedList *list, size_t index);
bool singly_linked_list_contains(const SinglyLinkedList *list, int value);
size_t singly_linked_list_size(const SinglyLinkedList *list);
void singly_linked_list_destroy(SinglyLinkedList *list);

#endif // SINGLY_LINKED_LIST_H

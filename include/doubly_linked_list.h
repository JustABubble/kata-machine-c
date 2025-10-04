#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* doubly_linked_list_create(void);
void doubly_linked_list_prepend(DoublyLinkedList *list, int value);
void doubly_linked_list_append(DoublyLinkedList *list, int value);
void doubly_linked_list_insert_at(DoublyLinkedList *list, size_t index, int value);
int doubly_linked_list_remove(DoublyLinkedList *list, int value);
int doubly_linked_list_remove_at(DoublyLinkedList *list, size_t index);
int doubly_linked_list_get(const DoublyLinkedList *list, size_t index);
bool doubly_linked_list_contains(const DoublyLinkedList *list, int value);
size_t doubly_linked_list_size(const DoublyLinkedList *list);
void doubly_linked_list_destroy(DoublyLinkedList *list);

#endif // DOUBLY_LINKED_LIST_H

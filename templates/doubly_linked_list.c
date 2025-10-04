#include "doubly_linked_list.h"
#include <stdlib.h>

struct DoublyLinkedList {
    // TODO: Define your doubly linked list structure
};

DoublyLinkedList* doubly_linked_list_create(void) {
    return NULL;
}

void doubly_linked_list_prepend(DoublyLinkedList *list, int value) {
    (void)list;
    (void)value;
}

void doubly_linked_list_append(DoublyLinkedList *list, int value) {
    (void)list;
    (void)value;
}

void doubly_linked_list_insert_at(DoublyLinkedList *list, size_t index, int value) {
    (void)list;
    (void)index;
    (void)value;
}

int doubly_linked_list_remove(DoublyLinkedList *list, int value) {
    (void)list;
    (void)value;
    return -1;
}

int doubly_linked_list_remove_at(DoublyLinkedList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

int doubly_linked_list_get(const DoublyLinkedList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

bool doubly_linked_list_contains(const DoublyLinkedList *list, int value) {
    (void)list;
    (void)value;
    return false;
}

size_t doubly_linked_list_size(const DoublyLinkedList *list) {
    (void)list;
    return 0;
}

void doubly_linked_list_destroy(DoublyLinkedList *list) {
    (void)list;
}

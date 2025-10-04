#include "singly_linked_list.h"
#include <stdlib.h>

struct SinglyLinkedList {
    // TODO: Define your singly linked list structure
};

SinglyLinkedList* singly_linked_list_create(void) {
    return NULL;
}

void singly_linked_list_prepend(SinglyLinkedList *list, int value) {
    (void)list;
    (void)value;
}

void singly_linked_list_append(SinglyLinkedList *list, int value) {
    (void)list;
    (void)value;
}

void singly_linked_list_insert_at(SinglyLinkedList *list, size_t index, int value) {
    (void)list;
    (void)index;
    (void)value;
}

int singly_linked_list_remove(SinglyLinkedList *list, int value) {
    (void)list;
    (void)value;
    return -1;
}

int singly_linked_list_remove_at(SinglyLinkedList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

int singly_linked_list_get(const SinglyLinkedList *list, size_t index) {
    (void)list;
    (void)index;
    return -1;
}

bool singly_linked_list_contains(const SinglyLinkedList *list, int value) {
    (void)list;
    (void)value;
    return false;
}

size_t singly_linked_list_size(const SinglyLinkedList *list) {
    (void)list;
    return 0;
}

void singly_linked_list_destroy(SinglyLinkedList *list) {
    (void)list;
}

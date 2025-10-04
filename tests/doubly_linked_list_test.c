#include "doubly_linked_list.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    ASSERT_BOOL_EQ(list != NULL, true, "Create list");
    doubly_linked_list_destroy(list);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy list" COLOR_RESET "\n");
}

void test_append(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    doubly_linked_list_append(list, 1);
    doubly_linked_list_append(list, 2);
    doubly_linked_list_append(list, 3);
    ASSERT_INT_EQ(doubly_linked_list_size(list), 3, "Append size");
    ASSERT_INT_EQ(doubly_linked_list_get(list, 0), 1, "Append get 0");
    ASSERT_INT_EQ(doubly_linked_list_get(list, 2), 3, "Append get 2");
    doubly_linked_list_destroy(list);
}

void test_prepend(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    doubly_linked_list_prepend(list, 3);
    doubly_linked_list_prepend(list, 2);
    doubly_linked_list_prepend(list, 1);
    ASSERT_INT_EQ(doubly_linked_list_get(list, 0), 1, "Prepend order");
    doubly_linked_list_destroy(list);
}

void test_insert_at(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    doubly_linked_list_append(list, 1);
    doubly_linked_list_append(list, 3);
    doubly_linked_list_insert_at(list, 1, 2);
    ASSERT_INT_EQ(doubly_linked_list_get(list, 1), 2, "Insert at middle");
    doubly_linked_list_destroy(list);
}

void test_remove(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    doubly_linked_list_append(list, 1);
    doubly_linked_list_append(list, 2);
    doubly_linked_list_append(list, 3);
    int removed = doubly_linked_list_remove(list, 2);
    ASSERT_INT_EQ(removed, 2, "Remove returns value");
    ASSERT_INT_EQ(doubly_linked_list_size(list), 2, "Size after remove");
    doubly_linked_list_destroy(list);
}

void test_remove_at(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    doubly_linked_list_append(list, 1);
    doubly_linked_list_append(list, 2);
    doubly_linked_list_append(list, 3);
    int removed = doubly_linked_list_remove_at(list, 1);
    ASSERT_INT_EQ(removed, 2, "Remove at returns value");
    ASSERT_INT_EQ(doubly_linked_list_get(list, 1), 3, "Element shifted");
    doubly_linked_list_destroy(list);
}

void test_bidirectional_removal(void) {
    DoublyLinkedList *list = doubly_linked_list_create();
    for (int i = 1; i <= 5; i++) {
        doubly_linked_list_append(list, i);
    }
    doubly_linked_list_remove_at(list, 0);  // Remove first
    doubly_linked_list_remove_at(list, doubly_linked_list_size(list) - 1);  // Remove last
    ASSERT_INT_EQ(doubly_linked_list_get(list, 0), 2, "First after removals");
    ASSERT_INT_EQ(doubly_linked_list_size(list), 3, "Size after both ends removed");
    doubly_linked_list_destroy(list);
}

int main(void) {
    printf(COLOR_BOLD "Running doubly_linked_list tests:\n" COLOR_RESET);

    test_create_destroy();
    test_append();
    test_prepend();
    test_insert_at();
    test_remove();
    test_remove_at();
    test_bidirectional_removal();

    PRINT_TEST_SUMMARY("doubly_linked_list");
    return test_failed > 0 ? 1 : 0;
}

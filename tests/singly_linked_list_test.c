#include "singly_linked_list.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    ASSERT_BOOL_EQ(list != NULL, true, "Create list");
    singly_linked_list_destroy(list);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy list" COLOR_RESET "\n");
}

void test_append(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_append(list, 1);
    singly_linked_list_append(list, 2);
    singly_linked_list_append(list, 3);
    ASSERT_INT_EQ(singly_linked_list_size(list), 3, "Append size");
    ASSERT_INT_EQ(singly_linked_list_get(list, 0), 1, "Append get 0");
    ASSERT_INT_EQ(singly_linked_list_get(list, 1), 2, "Append get 1");
    ASSERT_INT_EQ(singly_linked_list_get(list, 2), 3, "Append get 2");
    singly_linked_list_destroy(list);
}

void test_prepend(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_prepend(list, 3);
    singly_linked_list_prepend(list, 2);
    singly_linked_list_prepend(list, 1);
    ASSERT_INT_EQ(singly_linked_list_get(list, 0), 1, "Prepend get 0");
    ASSERT_INT_EQ(singly_linked_list_get(list, 1), 2, "Prepend get 1");
    ASSERT_INT_EQ(singly_linked_list_get(list, 2), 3, "Prepend get 2");
    singly_linked_list_destroy(list);
}

void test_insert_at(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_append(list, 1);
    singly_linked_list_append(list, 3);
    singly_linked_list_insert_at(list, 1, 2);
    ASSERT_INT_EQ(singly_linked_list_get(list, 0), 1, "Insert at 0");
    ASSERT_INT_EQ(singly_linked_list_get(list, 1), 2, "Insert at 1");
    ASSERT_INT_EQ(singly_linked_list_get(list, 2), 3, "Insert at 2");
    singly_linked_list_destroy(list);
}

void test_remove(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_append(list, 1);
    singly_linked_list_append(list, 2);
    singly_linked_list_append(list, 3);
    int removed = singly_linked_list_remove(list, 2);
    ASSERT_INT_EQ(removed, 2, "Remove returns value");
    ASSERT_INT_EQ(singly_linked_list_size(list), 2, "Size after remove");
    ASSERT_BOOL_EQ(singly_linked_list_contains(list, 2), false, "Value removed");
    singly_linked_list_destroy(list);
}

void test_remove_at(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_append(list, 1);
    singly_linked_list_append(list, 2);
    singly_linked_list_append(list, 3);
    int removed = singly_linked_list_remove_at(list, 1);
    ASSERT_INT_EQ(removed, 2, "Remove at returns value");
    ASSERT_INT_EQ(singly_linked_list_get(list, 1), 3, "Next element shifted");
    singly_linked_list_destroy(list);
}

void test_contains(void) {
    SinglyLinkedList *list = singly_linked_list_create();
    singly_linked_list_append(list, 1);
    singly_linked_list_append(list, 2);
    ASSERT_BOOL_EQ(singly_linked_list_contains(list, 2), true, "Contains existing");
    ASSERT_BOOL_EQ(singly_linked_list_contains(list, 99), false, "Contains non-existing");
    singly_linked_list_destroy(list);
}

int main(void) {
    printf(COLOR_BOLD "Running singly_linked_list tests:\n" COLOR_RESET);

    test_create_destroy();
    test_append();
    test_prepend();
    test_insert_at();
    test_remove();
    test_remove_at();
    test_contains();

    PRINT_TEST_SUMMARY("singly_linked_list");
    return test_failed > 0 ? 1 : 0;
}

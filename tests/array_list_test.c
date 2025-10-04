#include "array_list.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    ArrayList *list = array_list_create();
    ASSERT_BOOL_EQ(list != NULL, true, "Create list");
    array_list_destroy(list);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy list" COLOR_RESET "\n");
}

void test_append(void) {
    ArrayList *list = array_list_create();
    array_list_append(list, 1);
    array_list_append(list, 2);
    array_list_append(list, 3);
    ASSERT_INT_EQ(array_list_size(list), 3, "Append size");
    ASSERT_INT_EQ(array_list_get(list, 0), 1, "Get 0");
    ASSERT_INT_EQ(array_list_get(list, 2), 3, "Get 2");
    array_list_destroy(list);
}

void test_growth(void) {
    ArrayList *list = array_list_create();
    size_t initial_capacity = array_list_capacity(list);

    // Add enough elements to trigger growth
    for (int i = 0; i < 100; i++) {
        array_list_append(list, i);
    }

    ASSERT_INT_EQ(array_list_size(list), 100, "Size after many appends");
    ASSERT_BOOL_EQ(array_list_capacity(list) > initial_capacity, true, "Capacity grew");
    ASSERT_INT_EQ(array_list_get(list, 99), 99, "Last element correct");
    array_list_destroy(list);
}

void test_insert_at(void) {
    ArrayList *list = array_list_create();
    array_list_append(list, 1);
    array_list_append(list, 3);
    array_list_insert_at(list, 1, 2);
    ASSERT_INT_EQ(array_list_get(list, 1), 2, "Insert at middle");
    ASSERT_INT_EQ(array_list_size(list), 3, "Size after insert");
    array_list_destroy(list);
}

void test_remove_at(void) {
    ArrayList *list = array_list_create();
    array_list_append(list, 1);
    array_list_append(list, 2);
    array_list_append(list, 3);
    int removed = array_list_remove_at(list, 1);
    ASSERT_INT_EQ(removed, 2, "Remove at returns value");
    ASSERT_INT_EQ(array_list_get(list, 1), 3, "Element shifted");
    ASSERT_INT_EQ(array_list_size(list), 2, "Size after remove");
    array_list_destroy(list);
}

void test_set(void) {
    ArrayList *list = array_list_create();
    array_list_append(list, 1);
    array_list_append(list, 2);
    array_list_set(list, 1, 42);
    ASSERT_INT_EQ(array_list_get(list, 1), 42, "Set value");
    array_list_destroy(list);
}

int main(void) {
    printf(COLOR_BOLD "Running array_list tests:\n" COLOR_RESET);

    test_create_destroy();
    test_append();
    test_growth();
    test_insert_at();
    test_remove_at();
    test_set();

    PRINT_TEST_SUMMARY("array_list");
    return test_failed > 0 ? 1 : 0;
}

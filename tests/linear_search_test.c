#include "linear_search.h"
#include "test_helpers.h"

void test_empty_array(void) {
    int arr[] = {};
    bool result = linear_search(arr, 0, 42);
    ASSERT_BOOL_EQ(result, false, "Empty array");
}

void test_single_element_found(void) {
    int arr[] = {42};
    bool result = linear_search(arr, 1, 42);
    ASSERT_BOOL_EQ(result, true, "Single element found");
}

void test_single_element_not_found(void) {
    int arr[] = {42};
    bool result = linear_search(arr, 1, 7);
    ASSERT_BOOL_EQ(result, false, "Single element not found");
}

void test_element_at_beginning(void) {
    int arr[] = {1, 2, 3, 4, 5};
    bool result = linear_search(arr, 5, 1);
    ASSERT_BOOL_EQ(result, true, "Element at beginning");
}

void test_element_at_end(void) {
    int arr[] = {1, 2, 3, 4, 5};
    bool result = linear_search(arr, 5, 5);
    ASSERT_BOOL_EQ(result, true, "Element at end");
}

void test_element_in_middle(void) {
    int arr[] = {1, 2, 3, 4, 5};
    bool result = linear_search(arr, 5, 3);
    ASSERT_BOOL_EQ(result, true, "Element in middle");
}

void test_element_not_present(void) {
    int arr[] = {1, 2, 3, 4, 5};
    bool result = linear_search(arr, 5, 99);
    ASSERT_BOOL_EQ(result, false, "Element not present");
}

void test_duplicates(void) {
    int arr[] = {1, 2, 3, 2, 1};
    bool result = linear_search(arr, 5, 2);
    ASSERT_BOOL_EQ(result, true, "Duplicates");
}

void test_negative_numbers(void) {
    int arr[] = {-5, -3, -1, 0, 2, 3};
    bool result = linear_search(arr, 6, -3);
    ASSERT_BOOL_EQ(result, true, "Negative numbers");
}

void test_negative_not_found(void) {
    int arr[] = {-5, -3, -1, 0, 2, 3};
    bool result = linear_search(arr, 6, -10);
    ASSERT_BOOL_EQ(result, false, "Negative number not found");
}

int main(void) {
    printf(COLOR_BOLD "Running linear_search tests:\n" COLOR_RESET);

    test_empty_array();
    test_single_element_found();
    test_single_element_not_found();
    test_element_at_beginning();
    test_element_at_end();
    test_element_in_middle();
    test_element_not_present();
    test_duplicates();
    test_negative_numbers();
    test_negative_not_found();

    PRINT_TEST_SUMMARY("linear_search");
    return test_failed > 0 ? 1 : 0;
}
